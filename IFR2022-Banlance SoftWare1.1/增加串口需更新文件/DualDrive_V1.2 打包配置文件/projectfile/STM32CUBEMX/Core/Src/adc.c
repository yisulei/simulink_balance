/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.c
  * @brief   This file provides code for the configuration
  *          of the ADC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "adc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
DMA_HandleTypeDef hdma_adc1;
DMA_HandleTypeDef hdma_adc2;

/* ADC1 init function */
void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}
/* ADC2 init function */
void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.ScanConvMode = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc2.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T8_TRGO;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  hadc2.Init.DMAContinuousRequests = ENABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_56CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

void HAL_ADC_MspInit(ADC_HandleTypeDef* adcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspInit 0 */

  /* USER CODE END ADC1_MspInit 0 */
    /* ADC1 clock enable */
    __HAL_RCC_ADC1_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**ADC1 GPIO Configuration
    PC0     ------> ADC1_IN10
    PC2     ------> ADC1_IN12
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* ADC1 DMA Init */
    /* ADC1 Init */
    hdma_adc1.Instance = DMA2_Stream0;
    hdma_adc1.Init.Channel = DMA_CHANNEL_0;
    hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
    hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
    hdma_adc1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_adc1) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(adcHandle,DMA_Handle,hdma_adc1);

  /* USER CODE BEGIN ADC1_MspInit 1 */

  /* USER CODE END ADC1_MspInit 1 */
  }
  else if(adcHandle->Instance==ADC2)
  {
  /* USER CODE BEGIN ADC2_MspInit 0 */

  /* USER CODE END ADC2_MspInit 0 */
    /* ADC2 clock enable */
    __HAL_RCC_ADC2_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**ADC2 GPIO Configuration
    PC1     ------> ADC2_IN11
    */
    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* ADC2 DMA Init */
    /* ADC2 Init */
    hdma_adc2.Instance = DMA2_Stream2;
    hdma_adc2.Init.Channel = DMA_CHANNEL_1;
    hdma_adc2.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adc2.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adc2.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc2.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adc2.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_adc2.Init.Mode = DMA_CIRCULAR;
    hdma_adc2.Init.Priority = DMA_PRIORITY_LOW;
    hdma_adc2.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_adc2) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(adcHandle,DMA_Handle,hdma_adc2);

  /* USER CODE BEGIN ADC2_MspInit 1 */

  /* USER CODE END ADC2_MspInit 1 */
  }
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef* adcHandle)
{

  if(adcHandle->Instance==ADC1)
  {
  /* USER CODE BEGIN ADC1_MspDeInit 0 */

  /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC1_CLK_DISABLE();

    /**ADC1 GPIO Configuration
    PC0     ------> ADC1_IN10
    PC2     ------> ADC1_IN12
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_0|GPIO_PIN_2);

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);
  /* USER CODE BEGIN ADC1_MspDeInit 1 */

  /* USER CODE END ADC1_MspDeInit 1 */
  }
  else if(adcHandle->Instance==ADC2)
  {
  /* USER CODE BEGIN ADC2_MspDeInit 0 */

  /* USER CODE END ADC2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_ADC2_CLK_DISABLE();

    /**ADC2 GPIO Configuration
    PC1     ------> ADC2_IN11
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1);

    /* ADC2 DMA DeInit */
    HAL_DMA_DeInit(adcHandle->DMA_Handle);
  /* USER CODE BEGIN ADC2_MspDeInit 1 */

  /* USER CODE END ADC2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
#include "tim.h"
#include "math.h"
extern volatile uint16_t adc1_DMAData[10];	//ADC1 DMA Buffer
extern volatile uint16_t adc2_DMAData[10];	//ADC2 DMA Buffer
extern int16_t motor1_PwmData;	//As the name implies
extern int16_t motor2_PwmData;	//As the name implies

volatile uint16_t tim3cnt=0;
volatile uint16_t tim8cnt=0;

volatile uint32_t simulinkRunFlag[2]={0};// first bit reset by adc1; second bit reset by adc2; only when both of them reset will the simulink step funtion run
int16_t adc_rawvalue[2][5]={{0},{0}};	//Removal of raw data from underflow sampling points
int16_t adc_zerooffset[2]={0};

int16_t adc_avervalue[2]={0,0};
float adc_filtervalue[2]={0,0};
float adc_convVolt[2]={0};
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)	//once PWM trigger adc twice,10KHz PWM,20KHz trigger & DMA buffer 10Bytes --> 2KHz DMA full interupt, 2Khz currentPID 
{
	
	if(hadc->Instance == hadc1.Instance)
	{
		//uint16_t sum1=0;
		uint16_t ioffset=1;
		uint16_t signI=motor1_PwmData<0?-1:1;
		tim3cnt=__HAL_TIM_GetCounter(&htim3);
		if(tim3cnt<600) ioffset=0;
		for(int i=0;i<5;i++)
		{
			//sum1+=adc1_DMAData[i*2+ioffset];
			adc_rawvalue[0][i]=signI*(adc1_DMAData[i*2+ioffset]-adc_zerooffset[0]);
		}
//		if(motor1_PwmData<0)
//		{
//			adc_avervalue[0]=(2048-(int16_t)(sum1/5));
//		}
//		else
//		{
//			adc_avervalue[0]=(int16_t)(sum1/5)-2048;
//		}
//		adc_convVolt[0]=adc_avervalue[0]*33/2048.0f;
//		adc_filtervalue[0]=0.9f*adc_filtervalue[0]+0.1f*adc_convVolt[0];
		simulinkRunFlag[0]++;
	}
	else if(hadc->Instance == hadc2.Instance)
	{
		//uint16_t sum2=0;
		uint16_t signI=motor2_PwmData<0?-1:1;
		uint16_t ioffset=1;
		tim8cnt=__HAL_TIM_GetCounter(&htim8);
		if(tim8cnt<600) ioffset=0;
		for(int i=0;i<5;i++)
		{
			//sum2+=adc2_DMAData[i*2+ioffset];
			adc_rawvalue[1][i]=signI*(adc2_DMAData[i*2+ioffset]-adc_zerooffset[1]);
		}
//		if(motor2_PwmData<0)
//		{
//			adc_avervalue[1]=2048-(uint16_t)(sum2/5);
//		}
//		else
//		{
//			adc_avervalue[1]=(uint16_t)(sum2/5)-2048;
//		}
//		adc_convVolt[1]=adc_avervalue[1]*33/2048.0f;
//		adc_filtervalue[1]=0.9f*adc_filtervalue[1]+0.1f*adc_convVolt[1];
		simulinkRunFlag[1]++;
	}
	
//static uint16_t adc1_count,adc2_count=0;
//	if(hadc->Instance == hadc1.Instance)	//no dma
//	{
//		tim3cnt=__HAL_TIM_GetCounter(&htim3);
//		//timupdataflag=!timupdataflag;
//		if(tim3cnt<10)
//		{
//			adc_rawvalue[0][adc1_count]=HAL_ADC_GetValue(&hadc1);
//			simulinkRunFlag++;
//			adc1_count++;
//			if(adc1_count>9)
//			{
//				adc1_count=0;
//				uint16_t sum=0;
//				for(int i =0;i<10;i++)
//				{
//					sum += adc_rawvalue[0][i];
//				}
//				adc_filtervalue[0]=(uint16_t)(sum/10);
//			}
//		}
//	}
//	else if(hadc->Instance == hadc2.Instance)
//	{
//		tim8cnt=__HAL_TIM_GetCounter(&htim8);
//		if(tim8cnt<10)
//		{
//			adc_rawvalue[1][adc2_count]=HAL_ADC_GetValue(&hadc2);
//			
//			adc2_count++;
//			if(adc2_count>9)
//			{
//				adc2_count=0;
//				uint16_t sum=0;
//				for(int i =0;i<10;i++)
//				{
//					sum += adc_rawvalue[1][i];
//				}
//				adc_filtervalue[1]=(uint16_t)(sum/10);
//			}
//		}
//	}
	
}

void USER_ADC_Zero_calibration(void)
{
	uint16_t count=0;
	uint32_t sum1=0;
	uint32_t sum2=0;
	while(count<2000)
	{
		while(simulinkRunFlag[0]==0||simulinkRunFlag[1]==0){}	//wait data conv complete
		simulinkRunFlag[0]=0;
		simulinkRunFlag[1]=0;
		for(int i=0;i<5;i++)
		{
			sum1+=adc_rawvalue[0][i];
			sum2+=adc_rawvalue[1][i];
		}
		
		count++;
	}
	adc_zerooffset[0]=(int16_t)(sum1/10000);
	adc_zerooffset[1]=(int16_t)(sum2/10000);
}

/* USER CODE END 1 */
