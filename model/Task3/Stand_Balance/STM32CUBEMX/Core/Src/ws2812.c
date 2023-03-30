#include "stdio.h"
#include "stdbool.h"
#include "ws2812.h"

const uint8_t WS2812BitDef[2] ={WS2812BIT_LOW,WS2812BIT_HIGH};

//Assigning a colour to all LEDs
uint8_t UpdateOneColorToAllBit(uint8_t colors[3],uint16_t dmabuffer[],uint16_t led_nums)	//GRB
{
	if(led_nums>WS2812_NUMS)	return false;
	for(int i=0;i<led_nums;i++)
	{
		for(int channel=WS2812_GREEN;channel<WS2812_BLUE+1;channel++)	//???for??????
		{
			for(int bit=7;bit>=0;bit--)
			{
				dmabuffer[i*24+channel*8+(7-bit)]=WS2812BitDef[colors[channel]>>bit&0x01];
			}
		}
	}
	dmabuffer[led_nums*24]=0;
	return true;
}

//Assigning a specific colour to a specific LED
uint8_t UpdateOneColorsToDesignatedBit(uint8_t colors[3],uint8_t designated[], uint16_t dmabuffer[],uint16_t led_nums)
{
	if(led_nums>WS2812_NUMS)	return false;
	for(int i=0;i<led_nums;i++)
	{
		for(int channel=WS2812_GREEN;channel<WS2812_BLUE+1;channel++)	//???for??????
		{
			for(int bit=7;bit>=0;bit--)
			{
				dmabuffer[i*24+channel*8+(7-bit)]=WS2812BitDef[ (colors[channel]>>bit&0x01) &designated[i] ];
			}
		}
	}
	dmabuffer[led_nums*24]=0;
	return true;
}	

//Assigning individual colours to each LED
uint8_t UpdateColorsToBit(uint8_t colors[][3],uint16_t dmabuffer[],uint16_t led_nums)	//GRB
{
	if(led_nums>WS2812_NUMS)	return false;
	for(int i=0;i<led_nums;i++)
	{
		for(int channel=WS2812_GREEN;channel<WS2812_BLUE+1;channel++)	//???for??????
		{
			for(int bit=7;bit>=0;bit--)
			{
				dmabuffer[i*24+channel*8+(7-bit)]=WS2812BitDef[*(colors[i] + channel)>>bit&0x01];
			}
		}
	}
	dmabuffer[led_nums*24]=0;
	//Pwm3_1_Dmasetcounter=led_nums*24+1;
	return true;
}

void pwmdma_testinit(uint16_t dma1buffer[],uint16_t dma2buffer[])
{
	uint8_t color[2][3]={100,0,0,0,100,0};
	UpdateColorsToBit(color,dma1buffer,2);
	UpdateColorsToBit(color,dma2buffer,2);
}


/**
* @movestep Step size for each shift, with the positive direction being the direction of growth of the subscript
**/
void shift_by_byte(uint8_t bytes[],uint16_t nums,int16_t movestep)
{
	if(movestep>=nums) return;
	if(movestep>0)
	{
		for(int i =nums-1;i>=movestep;i--)
		{
			bytes[i]=bytes[i-movestep];
		}
	}
	else if(movestep<0)
	{
		for(int i =0;i<nums+movestep;i++)
		{
			bytes[i]=bytes[i-movestep];
		}
	}
}


//To be improved to pointer form, compatible with 1-dimensional arrays and 2-dimensional arrays
void ColorsRamp(uint8_t tarcolors[][3],uint8_t realcolors[][3],uint8_t rampstep,uint16_t led_nums)
{
	if(led_nums>WS2812_NUMS)	return;
	for(int i=0;i<led_nums;i++)
	{
		for(int channel=WS2812_GREEN;channel<WS2812_BLUE+1;channel++)	//???for??????
		{
			if((int8_t)(*(tarcolors[i] + channel) - *(realcolors[i] + channel)) > rampstep)
			{
				*(realcolors[i] + channel)+=rampstep;
			}
			else if((int8_t)(*(tarcolors[i] + channel) - *(realcolors[i] + channel)) < -rampstep)
			{
				*(realcolors[i] + channel)-=rampstep;
			}
			else
			{
				*(realcolors[i] + channel)=*(tarcolors[i] + channel);
			}
		}
	}
}

void OneColorRamp(uint8_t tarcolors[3],uint8_t realcolors[3],uint8_t rampstep)
{

	for(int channel=WS2812_GREEN;channel<WS2812_BLUE+1;channel++)	//???for??????
	{
		if((int16_t)(*(tarcolors + channel) - *(realcolors + channel)) > rampstep)
		{
			*(realcolors + channel)+=rampstep;
		}
		else if((int16_t)(*(tarcolors + channel) - *(realcolors + channel)) < -rampstep)
		{
			*(realcolors + channel)-=rampstep;
		}
		else
		{
			*(realcolors + channel)=*(tarcolors + channel);
		}
	}

}

uint8_t led_Designated[WS2812_NUMS]={0};// 1 light;0 off
extern uint16_t pwm4_1_DMAData[WS2812_NUMS*3*8+1];
extern unsigned int time_5ms_count;
static uint8_t tarcolors[3]={0};
static uint8_t sendcolors[3]={0};
void normal_LightingEffects(void)
{
	if(time_5ms_count%400==20)//GRB
	{
		tarcolors[0]=90;
		tarcolors[1]=0;
		tarcolors[2]=0;
	}
	else if(time_5ms_count%400==200)
	{
		tarcolors[0]=0;
		tarcolors[1]=0;
		tarcolors[2]=0;
	}
	
	
	if(time_5ms_count%5==0&&time_5ms_count>430)
	{
		shift_by_byte(led_Designated,WS2812_NUMS,1);
		led_Designated[0]=1;
	}
	
	if(time_5ms_count%2==0)
	{
		OneColorRamp(tarcolors,sendcolors,1);
		//UpdateOneColorToAllBit(sendcolors,pwm4_1_DMAData,WS2812_NUMS);
		UpdateOneColorsToDesignatedBit(sendcolors,led_Designated,pwm4_1_DMAData,WS2812_NUMS);
	}
}

void connecting_LightingEffects(void)
{
	if(time_5ms_count%300==0)
	{
		tarcolors[0]=120;
		tarcolors[1]=0;
		tarcolors[2]=0;
	}
	else if(time_5ms_count%300==100)
	{
		tarcolors[0]=0;
		tarcolors[1]=90;
		tarcolors[2]=0;
	}
	else if(time_5ms_count%300==200)
	{
		tarcolors[0]=0;
		tarcolors[1]=0;
		tarcolors[2]=120;
	}
	
	
	if(time_5ms_count%5==0)
	{
		shift_by_byte(led_Designated,WS2812_NUMS,1);
		if(time_5ms_count%155==0||time_5ms_count%155==5)//10*30+10=310  //5*30+5=155
		{
			led_Designated[0]=1;
		}
		else
		{
			led_Designated[0]=0;
		}
	}
	
	if(time_5ms_count%2==0)
	{
		OneColorRamp(tarcolors,sendcolors,1);
		//UpdateOneColorToAllBit(sendcolors,pwm4_1_DMAData,WS2812_NUMS);
		UpdateOneColorsToDesignatedBit(sendcolors,led_Designated,pwm4_1_DMAData,WS2812_NUMS);
	}
}

void connected_LightingEffects(void)
{
		if(time_5ms_count%400==20)//GRB
	{
		tarcolors[0]=0;
		tarcolors[1]=0;
		tarcolors[2]=90;
	}
	else if(time_5ms_count%400==200)
	{
		tarcolors[0]=0;
		tarcolors[1]=0;
		tarcolors[2]=0;
	}
	
	
	if(time_5ms_count%5==0)
	{
		shift_by_byte(led_Designated,WS2812_NUMS,1);
		led_Designated[0]=1;
	}
	
	if(time_5ms_count%2==0)
	{
		OneColorRamp(tarcolors,sendcolors,1);
		//UpdateOneColorToAllBit(sendcolors,pwm4_1_DMAData,WS2812_NUMS);
		UpdateOneColorsToDesignatedBit(sendcolors,led_Designated,pwm4_1_DMAData,WS2812_NUMS);
	}
}
