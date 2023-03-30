#include "uart_fifo.h"
#include <string.h>

volatile int protect_flag=0;
////FIFO队列相关 by余鑫 2018：
//入队列
bool InsertQueue( USART_CircularQueueTypeDef *q, const uint8_t* source,uint16_t len)//USART_FIFO_SIZE
{
	//__disable_irq();  /* Disable global interrupt*/
	
	if(len<=GetQueueWriteCount(q)&&len>0)
	{
		if(q->FIFO_Front + len < USART_FIFO_SIZE)	//若存入数据未到队列边界
		{
			memcpy(&q->SoftWare_FIFO[q->FIFO_Front], source, len);
			q->FIFO_Front+=len;
		}
		else
		{
			unsigned int len_front=USART_FIFO_SIZE - q->FIFO_Front;
			memcpy(&q->SoftWare_FIFO[q->FIFO_Front], source, len_front);//从front到end
			memcpy(&q->SoftWare_FIFO[0], (source+len_front), len-len_front);	//从头至剩下led	//这里source+len_front需要测试  
			q->FIFO_Front=len-len_front;
		}
	}
	else
	{
		return false;
	}
	//__enable_irq();    /*  Enable global interrupt */
	return true;
}

//出队列操作
bool RemoveQueue(uint8_t* destination, USART_CircularQueueTypeDef *q,uint16_t len)
{
	//__disable_irq();  /* Disable global interrupt*/
	//protect_flag=1;
	if(len<=GetQueueReadCount(q)&&len>0)
	{
		if(q->FIFO_Rear + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
		{
			memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len);
			q->FIFO_Rear+=len;
		}
		else
		{
			unsigned int len_front=USART_FIFO_SIZE - q->FIFO_Rear;
			memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len_front);//从front到end
			memcpy(destination+len_front, &q->SoftWare_FIFO[0], len-len_front);	//从头至剩下led
			q->FIFO_Rear=len-len_front;
		}
	}
	else
	{
		return false;
	}
	//__enable_irq();    /*  Enable global interrupt */
	//protect_flag=0;
	return true;
}

//出一个元素操作
char RemoveAQueue( USART_CircularQueueTypeDef *q)
{
	uint16_t len=1;
	char re_char;
	if(len<=GetQueueReadCount(q)&&len>0)
	{
		if(q->FIFO_Rear + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
		{
			//memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len);
			
			re_char = q->SoftWare_FIFO[q->FIFO_Rear];
			q->FIFO_Rear+=len;
		}
		else
		{
			unsigned int len_front=USART_FIFO_SIZE - q->FIFO_Rear;
			//memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len_front);//从front到end
			
			re_char = q->SoftWare_FIFO[q->FIFO_Rear];
			q->FIFO_Rear=len-len_front;
		}
		return re_char;
	}
	else
	{
		return false;
	}
	
	return true;
}

/**    移出当前所有队列可读元素   **/
uint16_t RemoveAllQueue(uint8_t* destination, USART_CircularQueueTypeDef *q)	//移出当前所有队列可读元素
{
	uint16_t len=GetQueueReadCount(q);
	if(len>0)
	{
		if(q->FIFO_Rear + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
		{
			memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len);
			q->FIFO_Rear+=len;
		}
		else
		{
			uint16_t len_front=USART_FIFO_SIZE - q->FIFO_Rear;
			memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len_front);//从front到end
			memcpy(destination+len_front, &q->SoftWare_FIFO[0], len-len_front);	//从头至剩下led
			q->FIFO_Rear=len-len_front;
		}
	}
	else
	{
		return 0;
	}
	
	return len;
}

//char* GetCurrentQueuePoint()

//查询队列
bool QueryQueue(uint8_t* destination,  USART_CircularQueueTypeDef const * queue, uint16_t distance, uint16_t len)
{
	if(distance+len<=GetQueueReadCount(queue)&&len>0)	//读取范围在队列可读范围内
	{
		unsigned int start=(queue->FIFO_Rear+distance)%USART_FIFO_SIZE;
	
		if(start + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
		{
			memcpy(destination, &queue->SoftWare_FIFO[start], len);
			//q->FIFO_Rear+=len;
		}
		else
		{
			unsigned int len_front=USART_FIFO_SIZE - start;
			memcpy(destination, &queue->SoftWare_FIFO[start], len_front);//从front到end
			memcpy(destination+len_front, &queue->SoftWare_FIFO[0], len-len_front);	//从头至剩下led
			//q->FIFO_Rear=len-len_front;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

//查询队列一个元素
char QueryAQueue( USART_CircularQueueTypeDef const * queue, uint16_t distance)
{
	uint16_t len=1;
	if(distance+len<=GetQueueReadCount(queue)&&len>0)	//读取范围在队列可读范围内
	{ 
		unsigned int start=(queue->FIFO_Rear+distance)%USART_FIFO_SIZE;
	
		return queue->SoftWare_FIFO[start];
//		if(start + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
//		{
//			memcpy(destination, &queue->SoftWare_FIFO[start], len);
//			//q->FIFO_Rear+=len;
//			return q->SoftWare_FIFO[q->FIFO_Rear];
//		}
//		else
//		{
//			unsigned int len_front=USART_FIFO_SIZE - start;
//			memcpy(destination, &queue->SoftWare_FIFO[start], len_front);//从front到end
//			memcpy(destination, &queue->SoftWare_FIFO[0], len-len_front);	//从头至剩下led
//			//q->FIFO_Rear=len-len_front;
//			return q->SoftWare_FIFO[q->FIFO_Rear];
//		}
	}
	else
	{
		return false;
	}
	
	return true;
}

bool DeleteQueue( USART_CircularQueueTypeDef * q, uint16_t len)	//就是在移出队列的基础上删除了memcpy
{
	if(len<=GetQueueReadCount(q)&&len>0)
	{
		if(q->FIFO_Rear + len < USART_FIFO_SIZE)	//若取出数据范围未到队列边界
		{
			//memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len);
			q->FIFO_Rear+=len;
		}
		else
		{
			unsigned int len_front=USART_FIFO_SIZE - q->FIFO_Rear;
			//memcpy(destination, &q->SoftWare_FIFO[q->FIFO_Rear], len_front);//从front到end
			//memcpy(destination, &q->SoftWare_FIFO[0], len-len_front);	//从头至剩下led
			q->FIFO_Rear=len-len_front;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

void DeleteAllQueue( USART_CircularQueueTypeDef * queue)
{
    queue->FIFO_Front=0;
    queue->FIFO_Rear=0;
}

uint16_t GetQueueReadCount( USART_CircularQueueTypeDef const * queue)	//传递指针而非值可以节约栈控件并提升效率，加上const修饰避免被修改
{
	if(queue->FIFO_Front==queue->FIFO_Rear)	return 0;//return QueueEmpty;
	if(queue->FIFO_Rear-queue->FIFO_Front==1||queue->FIFO_Rear-queue->FIFO_Front==-(USART_FIFO_SIZE-1))	return USART_FIFO_SIZE-1;//return QueueFull;
	return (queue->FIFO_Front - queue->FIFO_Rear)>=0?(queue->FIFO_Front - queue->FIFO_Rear):(queue->FIFO_Front - queue->FIFO_Rear+USART_FIFO_SIZE);
}

uint16_t GetQueueWriteCount( USART_CircularQueueTypeDef const * queue)	//传递指针而非值可以节约栈控件并提升效率，加上const修饰避免被修改
{
	if(queue->FIFO_Front==queue->FIFO_Rear)	return USART_FIFO_SIZE-1;//return QueueEmpty;
	if(queue->FIFO_Rear-queue->FIFO_Front==1||queue->FIFO_Rear-queue->FIFO_Front==-(USART_FIFO_SIZE-1))	return 0;
	return (queue->FIFO_Rear - queue->FIFO_Front-1)>=0?(queue->FIFO_Rear - queue->FIFO_Front-1):(queue->FIFO_Rear - queue->FIFO_Front-1+USART_FIFO_SIZE);
}

