//author YuXin
//time 2022/10/18
//Version 1.0
#include "ifr-scope_device.h"
#include "uart_fifo.h"
#include "string.h"
#include "stdbool.h"
#include "usart.h"

extern unsigned int time_5ms_count;
extern USART_CircularQueueTypeDef USART1_Software_FIFO;

enum _IFRScopeRunState IFRScopeRunState;

char WFDBG_REP_DESCRI[15]="Banlance-1";
char WFDBG_HANDSHAKE[6]="IFR00";
char WFDBG_REPDCY[]="#IFR=1:IM=Banlance-1;STA=1;#END";
/**********C************/
/*       ??       */
const char WFDBG_HEAD[]="#IFR=";
const char WFDBG_END[]="#END";

/*       ??????       */
const char WFDBG_REP_DCY1[]="#IFR=1:IM=";
const char WFDBG_REP_DCY2[]=";STA=1;#END";

const char WFDBG_IM[]="IM=";
const char WFDBG_STA[]="STA=";
/*      HOST?????     */
const char WFDBG_HANDSHAKE_HEAD[]="#IFR=_:";//!!!!!
const char WFDBG_HANDSHAKE_KEY[]="KEY=";

/*        connect ok         */
const char WFDBG_HANDSHAKE_OK[]="#IFR=`:#END";
const char WFDBG_HANDSHAKE_Fail[]="#IFR=a:#END";
/**data**/
const char WFDBG_DATA_MASK[]="MASK=";

/**Query queue based comparison with specified string**/
bool Compare_QueryQueue(USART_CircularQueueTypeDef const * queue, const char ch_source[])	//??????????????,?????false
{
	uint16_t ch_len=strlen(ch_source);
	
	if(ch_len>GetQueueReadCount(queue)) return false;
	
	for(int i=0;i<ch_len;i++)
	{
		if(QueryAQueue(queue,i)!=ch_source[i])	return false;
	}
	return true;
}
/**    Query the first occurrence of a substring in the string Return -1 if none   **/
uint32_t Get_Str_IndexOf(const char * str1, const char * str2)	//??strstr()
{
	char* index=strstr(str1,str2);
	if(index!=NULL)
	{
		return (uint32_t)(index-str1);
	}
	else
	{
		return 0;
	}
}

/**     Querying a substring in a queue without taking out the queue    **/
int32_t Get_Str_IndexOfQueue(USART_CircularQueueTypeDef const * queue, const char ch_source[])
{
	uint16_t ch_len=strlen(ch_source);
	uint16_t data_lengh=GetQueueReadCount(queue);
	
	if(ch_len>data_lengh) return -1;
	
	for(int i=0;i<=data_lengh-ch_len;i++)
	{//QueryQueue(data,queue,len) //It is more efficient to retrieve all the data at once and then compare them
		if(QueryAQueue(queue,i)==ch_source[0])
		{
			//uint8_t compflag=1;
			for(int stri=1;stri<ch_len;stri++)
			{
				if(QueryAQueue(queue,i+stri)!=ch_source[stri]) break;
			}
			return i;
		}
	}
	return -1;
}

/**      Move forward based on the current tail of the queue to find the head of the protocol: #IFR= If present, move the tail of the queue behind the head of the frame      **/
bool Find_IFR_Head(USART_CircularQueueTypeDef * queue)	//???????????:#RM-DT=
{
	if(RemoveAQueue(&USART1_Software_FIFO)==WFDBG_HEAD[0])	//??OK	WFDBG_HEAD[0]='#'
	{
		if(Compare_QueryQueue(queue,&WFDBG_HEAD[1])==true)	//Find #IFR=
		{
			DeleteQueue(queue,strlen(&WFDBG_HEAD[1]));
			
			return true;

		}
	}
	
	return false;
}

struct _framedata FrameData={
.head="#IFR=7:",
.link='=',
.end=";#END"
};

union _floatchar ReceiveData[10];

//5ms
void IFR_Scope_Main(void)
{
	switch(IFRScopeRunState)
	{
		case Unconnected:
		{
			//check handshake frame
			if(Find_IFR_Head(&USART1_Software_FIFO)==true)
			{
				//if(Compare_QueryQueue(&USART1_Software_FIFO,WFDBG_END)==false) return;//No full frame,wait next
				if(RemoveAQueue(&USART1_Software_FIFO)==FrameID_SimpHandShake)
				{
					if(Get_Str_IndexOfQueue(&USART1_Software_FIFO,WFDBG_HANDSHAKE_KEY)!=-1)	//Find #IFR=
					{
						char keydata[6]={0};
						DeleteQueue(&USART1_Software_FIFO,strlen(WFDBG_HANDSHAKE_KEY)+1);
						
						RemoveQueue((uint8_t*)keydata,&USART1_Software_FIFO,5);
						if(strcmp(keydata,WFDBG_HANDSHAKE)==0)
						{
							IFRScopeRunState=ConnectedNoData;
							HAL_UART_Transmit_DMA(&huart1, (uint8_t*)WFDBG_HANDSHAKE_OK, strlen(WFDBG_HANDSHAKE_OK));
						}
						else
						{//Key verification failure
							
							HAL_UART_Transmit_DMA(&huart1, (uint8_t*)WFDBG_HANDSHAKE_Fail, strlen(WFDBG_HANDSHAKE_Fail));
						}
					}
				}
			}
			else
			{
				DeleteAllQueue(&USART1_Software_FIFO);
				if(time_5ms_count%400==100)
				{
					HAL_UART_Transmit_DMA(&huart1, (uint8_t*)WFDBG_REPDCY, strlen(WFDBG_REPDCY));
				}
			}
			break;
		}
		case ConnectedNoData:
		{
			//check dataStart frame
			if(Find_IFR_Head(&USART1_Software_FIFO)==true)
			{
				//if(Compare_QueryQueue(&USART1_Software_FIFO,WFDBG_END)==false) return;//No full frame,wait next
				if(RemoveAQueue(&USART1_Software_FIFO)==FrameID_StartData)
				{
					IFRScopeRunState=ConnectedDataSend;
				}
			}
			else
			{
				DeleteAllQueue(&USART1_Software_FIFO);
			}
			break;
		}
		case ConnectedDataSend:
		{//todo: add quit connect when host stop
//			if(Find_IFR_Head(&USART1_Software_FIFO)==true)
//			{
//				uint8_t frameid = RemoveAQueue(&USART1_Software_FIFO);
//				if(frameid==FrameID_Data)
//				{
//					uint32_t maski = Get_Str_IndexOfQueue(&USART1_Software_FIFO,WFDBG_DATA_MASK);
//					DeleteQueue(&USART1_Software_FIFO,maski+strlen(WFDBG_DATA_MASK));//maski+5
//					//The end of the queue now points to the mask value
//					uint8_t maskvalue[10]={0};
//					RemoveQueue(maskvalue,&USART1_Software_FIFO,10);
//					if(RemoveAQueue(&USART1_Software_FIFO)==';')//MASK 10bytes -end
//					{
//						DeleteQueue(&USART1_Software_FIFO,2);//delete seq=
//						for(int i =0; i<10; i++)
//						{
//							if(maskvalue[i]==1)
//							{
//								RemoveQueue((uint8_t *)&(ReceiveData[i]),&USART1_Software_FIFO,4);
//							}
//							else //disable this chdata
//							{
//								DeleteQueue(&USART1_Software_FIFO,4);
//							}
//						}
//					}
//				}
//				else if(frameid==FrameID_Heartbeat)
//				{
//					
//				}
//			}
			
			if(time_5ms_count%2==0)//10MS FrameData
			{
				FrameData.data[1].point=1.1f;
				FrameData.data[2].point=2.2f;
				FrameData.data[3].point=3.3f;
				FrameData.data[4].point=time_5ms_count%1000;
				HAL_UART_Transmit_DMA(&huart1, (uint8_t*)&FrameData, sizeof(FrameData));
			}
			break;
		}
	}
}

