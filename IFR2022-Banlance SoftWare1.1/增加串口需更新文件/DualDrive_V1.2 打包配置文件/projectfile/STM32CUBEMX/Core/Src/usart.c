/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "stm32f4xx_hal.h"
#include "uart_fifo.h"
#include "string.h"
extern uint8_t Uart3DMABuffer[UART3DMA_RXBUFFER_SIZE];
extern uint8_t Uart4DMABuffer[UART4DMA_RXBUFFER_SIZE];
UartDMADataTypeDef Uart1DMAData;
USART_CircularQueueTypeDef USART1_Software_FIFO={0};
uint16_t UART1_DMA_NDTR=0;
/* USER CODE END 0 */

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef hdma_uart4_rx;
DMA_HandleTypeDef hdma_uart4_tx;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart3_rx;

/* UART4 init function */
void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 921600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}
/* UART5 init function */
void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 921600;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}
/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 921600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 921600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspInit 0 */

  /* USER CODE END UART4_MspInit 0 */
    /* UART4 clock enable */
    __HAL_RCC_UART4_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**UART4 GPIO Configuration
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* UART4 DMA Init */
    /* UART4_RX Init */
    hdma_uart4_rx.Instance = DMA1_Stream2;
    hdma_uart4_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_uart4_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_uart4_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_uart4_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_uart4_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_uart4_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_uart4_rx.Init.Mode = DMA_NORMAL;
    hdma_uart4_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_uart4_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_uart4_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_uart4_rx);

    /* UART4_TX Init */
    hdma_uart4_tx.Instance = DMA1_Stream4;
    hdma_uart4_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_uart4_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_uart4_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_uart4_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_uart4_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_uart4_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_uart4_tx.Init.Mode = DMA_NORMAL;
    hdma_uart4_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_uart4_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_uart4_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_uart4_tx);

    /* UART4 interrupt Init */
    HAL_NVIC_SetPriority(UART4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspInit 1 */

  /* USER CODE END UART4_MspInit 1 */
  }
  else if(uartHandle->Instance==UART5)
  {
  /* USER CODE BEGIN UART5_MspInit 0 */

  /* USER CODE END UART5_MspInit 0 */
    /* UART5 clock enable */
    __HAL_RCC_UART5_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**UART5 GPIO Configuration
    PC12     ------> UART5_TX
    PD2     ------> UART5_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /* USER CODE BEGIN UART5_MspInit 1 */

  /* USER CODE END UART5_MspInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA2_Stream5;
    hdma_usart1_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1_TX Init */
    hdma_usart1_tx.Instance = DMA2_Stream7;
    hdma_usart1_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart1_tx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */
  
  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 DMA Init */
    /* USART3_RX Init */
    hdma_usart3_rx.Instance = DMA1_Stream1;
    hdma_usart3_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart3_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart3_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart3_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart3_rx.Init.Mode = DMA_NORMAL;
    hdma_usart3_rx.Init.Priority = DMA_PRIORITY_MEDIUM;
    hdma_usart3_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart3_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart3_rx);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */
	
  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==UART4)
  {
  /* USER CODE BEGIN UART4_MspDeInit 0 */

  /* USER CODE END UART4_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART4_CLK_DISABLE();

    /**UART4 GPIO Configuration
    PC10     ------> UART4_TX
    PC11     ------> UART4_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);

    /* UART4 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* UART4 interrupt Deinit */
    HAL_NVIC_DisableIRQ(UART4_IRQn);
  /* USER CODE BEGIN UART4_MspDeInit 1 */

  /* USER CODE END UART4_MspDeInit 1 */
  }
  else if(uartHandle->Instance==UART5)
  {
  /* USER CODE BEGIN UART5_MspDeInit 0 */

  /* USER CODE END UART5_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_UART5_CLK_DISABLE();

    /**UART5 GPIO Configuration
    PC12     ------> UART5_TX
    PD2     ------> UART5_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

  /* USER CODE BEGIN UART5_MspDeInit 1 */

  /* USER CODE END UART5_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

HAL_StatusTypeDef HAL_UART_DMA_StopTx(UART_HandleTypeDef *huart)
{
	/* The Lock is not implemented on this API to allow the user application
	to call the HAL UART API under callbacks HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback():
	when calling HAL_DMA_Abort() API the DMA TX/RX Transfer complete interrupt is generated
	and the correspond call back is executed HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback()
	*/
	/* Disable the UART Tx/Rx DMA requests */
	huart->Instance->CR3 &= ~USART_CR3_DMAT;
	/* Abort the UART DMA rx Stream */
	if(huart->hdmatx != NULL)
	{
		HAL_DMA_Abort(huart->hdmatx);
	}
	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
		huart->gState = HAL_UART_STATE_BUSY_RX;
	else
		huart->gState = HAL_UART_STATE_READY;
	return HAL_OK;
}
//#include "stm32f4xx.h"
HAL_StatusTypeDef HAL_UART_DMA_StopRx(UART_HandleTypeDef *huart)
{
	/* The Lock is not implemented on this API to allow the user application
	to call the HAL UART API under callbacks HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback():
	when calling HAL_DMA_Abort() API the DMA TX/RX Transfer complete interrupt is generated
	and the correspond call back is executed HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback()
	*/
	/* Stop UART DMA Rx request if ongoing */
	uint32_t dmarequest = 0x00U;
	dmarequest = HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR);
	if ((huart->RxState == HAL_UART_STATE_BUSY_RX) && dmarequest)
	{
		ATOMIC_CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

		/* Abort the UART DMA Rx stream */
		if (huart->hdmarx != NULL)
		{
		  HAL_DMA_Abort(huart->hdmarx);
		}
		//UART_EndRxTransfer(huart);//static Expand start
		/* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
		  ATOMIC_CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE));
		  ATOMIC_CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);

		  /* In case of reception waiting for IDLE event, disable also the IDLE IE interrupt source */
		  if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
		  {
			ATOMIC_CLEAR_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
		  }

		  /* At end of Rx process, restore huart->RxState to Ready */
		  huart->RxState = HAL_UART_STATE_READY;
		  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;
		//static Expand start
	}
	return HAL_OK;
}

uint8_t achCRCHi[]={ 0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64,0,193,129,64,1,192,128,65,0,193,129,64,1,192,128,65,1,192,128,65,0,193,129,64};
uint8_t achCRCLo[]={ 0,192,193,1,195,3,2,194,198,6,7,199,5,197,196,4,204,12,13,205,15,207,206,14,10,202,203,11,201,9,8,200,216,24,25,217,27,219,218,26,30,222,223,31,221,29,28,220,20,212,213,21,215,23,22,214,210,18,19,211,17,209,208,16,240,48,49,241,51,243,242,50,54,246,247,55,245,53,52,244,60,252,253,61,255,63,62,254,250,58,59,251,57,249,248,56,40,232,233,41,235,43,42,234,238,46,47,239,45,237,236,44,228,36,37,229,39,231,230,38,34,226,227,35,225,33,32,224,160,96,97,161,99,163,162,98,102,166,167,103,165,101,100,164,108,172,173,109,175,111,110,174,170,106,107,171,105,169,168,104,120,184,185,121,187,123,122,186,190,126,127,191,125,189,188,124,180,116,117,181,119,183,182,118,114,178,179,115,177,113,112,176,80,144,145,81,147,83,82,146,150,86,87,151,85,149,148,84,156,92,93,157,95,159,158,94,90,154,155,91,153,89,88,152,136,72,73,137,75,139,138,74,78,142,143,79,141,77,76,140,68,132,133,69,135,71,70,134,130,66,67,131,65,129,128,64};
	
uint16_t CalcCRC_Modbus(uint8_t MsgToCRC[],int MsgLenToCRC)
{
	uint8_t crchi = 0xff;
	uint8_t crclo = 0xff;
	int idx=0;
	for(idx=0;idx<MsgLenToCRC;idx++)
	{
		uint8_t idxCRC = (uint8_t)(crchi^MsgToCRC[idx]);
		crchi = (uint8_t)( crclo^achCRCHi[idxCRC] );
        crclo = (uint8_t)( achCRCLo[idxCRC] );
	}
	return crchi<<8|crclo;
}

static void crc16_update(uint16_t *currect_crc, const uint8_t *src, uint32_t len)
{
    uint32_t crc = *currect_crc;
    uint32_t j;
    for (j=0; j < len; ++j)
    {
        uint32_t i;
        uint32_t byte = src[j];
        crc ^= byte << 8;
        for (i = 0; i < 8; ++i)
        {
            uint32_t temp = crc << 1;
            if (crc & 0x8000)
            {
                temp ^= 0x1021;
            }
            crc = temp;
        }
    } 
    *currect_crc = crc;
}

uint16_t DMA_NDTR=0;
uint16_t uart3rx_bufnum=0;
int16_t HI226_Angle[3]={0};
int16_t HI226_AngleV[3]={0};
uint16_t HI226_len = 0;
uint16_t HI226_Recvcrc = 0;
uint16_t HI226_Calccrc = 0;
uint16_t HI226_ErrorCount=0;
uint16_t HI226_FreqCount = 0;
uint8_t HI226_Decode(uint8_t *buffer,uint16_t length,int16_t *angle,int16_t *angle_v)
{
	if(buffer[0]==0x5A&&buffer[1]==0xA5)
	{
		HI226_len=buffer[2]|buffer[3]<<8;
		HI226_Recvcrc=buffer[4]|buffer[5]<<8;
//		for(int i=5;i>=2;i--)//Removing CRC fields, filling buffer
//		{
//			buffer[i]=buffer[i-2];
//		}
		HI226_Calccrc=0;
		crc16_update(&HI226_Calccrc, buffer, 4);
		crc16_update(&HI226_Calccrc, &buffer[6], HI226_len);
		if(HI226_Calccrc==HI226_Recvcrc)
		{
			for(int i=6;i<length-6;i++)
			{
				if(buffer[i]==0xB0)	//angle_v
				{
					angle_v[0]=buffer[i+1]|buffer[i+2]<<8;
					angle_v[1]=buffer[i+3]|buffer[i+4]<<8;
					angle_v[2]=buffer[i+5]|buffer[i+6]<<8;
				}
				else if(buffer[i]==0xD0)	//angle
				{
					angle[0]=buffer[i+1]|buffer[i+2]<<8;
					angle[1]=buffer[i+3]|buffer[i+4]<<8;
					angle[2]=buffer[i+5]|buffer[i+6]<<8;
				}
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

uint16_t uart4rx_bufnum=0;
int32_t RPi_Revdata[4]={0};
uint8_t RPi_DataDecode(uint8_t *buffer,uint16_t length,int32_t *data)
{
	if(length==21)
	{
		if(buffer[0]==0x5A&&buffer[1]==0xA5)
		{
			//for(int i=0;i<4;i++)
			//{
				memcpy(RPi_Revdata,&buffer[3],16);
			//}
		}
	}
	return 1;
}

int32_t RPi_SendData[4]={0};
uint8_t RPi_SendBuffer[21]={0};
void RPi_DataSend(int32_t *data)
{
	RPi_SendBuffer[0]=0x5A;
	RPi_SendBuffer[1]=0xA5;
	RPi_SendBuffer[2]=0x01;
	memcpy(&RPi_SendBuffer[3],data,16);
	HAL_UART_Transmit_DMA(&huart4, RPi_SendBuffer, 21);
}

uint32_t uart1rev_errorconut=0;
void USER_UART_RxIdleCallback(UART_HandleTypeDef *huart)
{
	
	if(huart->Instance==huart1.Instance)
	{
		if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET))
		{
			__HAL_UART_CLEAR_IDLEFLAG(huart);
			UART1_DMA_NDTR=__HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
			
			
			if(UART1_DMA_NDTR<UART1DMA_RXBUFFER_SIZE)  //??DMA?????????IDLE &&UART1_DMA_NDTR!=0
			{//The first frame after a soft reboot will have NDTR=0 and all buffer is 0
				//HAL_UART_DMAStop(huart);
				HAL_UART_DMA_StopRx(huart);
				
				Uart1DMAData.rxBufNum = UART1DMA_RXBUFFER_SIZE - UART1_DMA_NDTR;
				Uart1DMAData.rxFlag=1;
				if(InsertQueue(&USART1_Software_FIFO,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum)==false)
				{
					//HAL_GPIO_TogglePin(USER_LED_GPIO_Port,USER_LED_Pin);
				}

				if(HAL_UART_Receive_DMA(&huart1, Uart1DMAData.rxDMABuf, UART1DMA_RXBUFFER_SIZE)!=HAL_OK)
				{
					uart1rev_errorconut++;
				}
 
			}
		}
	}
	else if(huart->Instance==huart3.Instance)
	{
		if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET))
		{
			uint8_t t = huart->Instance->SR;
			t = huart->Instance->DR;
			  __HAL_UART_CLEAR_IDLEFLAG(huart);
			  DMA_NDTR=__HAL_DMA_GET_COUNTER(&hdma_usart3_rx);
			
			  if(DMA_NDTR<UART3DMA_RXBUFFER_SIZE)  //??DMA?????????IDLE
			  {
				HAL_UART_DMA_StopRx(huart);
				uart3rx_bufnum = UART3DMA_RXBUFFER_SIZE - DMA_NDTR;
				if(uart3rx_bufnum==20)
				{
					if(HI226_Decode(Uart3DMABuffer,uart3rx_bufnum,HI226_Angle,HI226_AngleV)==0)
					{
						HI226_ErrorCount++;
					}
					else
					{
						HI226_FreqCount++;
					}
				}
				HAL_UART_Receive_DMA(&huart3,Uart3DMABuffer,UART3DMA_RXBUFFER_SIZE);
				
			  }
			
		}
	}
	else if(huart->Instance==huart4.Instance)
	{
		if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET))
		{
			uint8_t t = huart->Instance->SR;
			t = huart->Instance->DR;
			  __HAL_UART_CLEAR_IDLEFLAG(huart);
			  DMA_NDTR=__HAL_DMA_GET_COUNTER(&hdma_uart4_rx);
			
			  if(DMA_NDTR<UART4DMA_RXBUFFER_SIZE)  //??DMA?????????IDLE
			  {
				HAL_UART_DMA_StopRx(huart);
				uart4rx_bufnum = UART4DMA_RXBUFFER_SIZE - DMA_NDTR;

				RPi_DataDecode(Uart4DMABuffer,uart4rx_bufnum,RPi_Revdata);
				//Deal(Uart3DMABuffer,uart3rx_bufnum,HI226_Angle,HI226_AngleV)
				HAL_UART_Receive_DMA(&huart4,Uart4DMABuffer,UART4DMA_RXBUFFER_SIZE);
				
			  }
			
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart)
{
    if(huart->Instance==huart3.Instance)
	{
      
      HAL_UART_Receive_DMA(&huart3,Uart3DMABuffer,UART3DMA_RXBUFFER_SIZE);
			
      
      {//debug
        //HAL_GPIO_WritePin(USER_LED2_GPIO_Port,USER_LED2_Pin,1);//??
        //HAL_GPIO_TogglePin(USER_LED2_GPIO_Port,USER_LED2_Pin);
        //HAL_UART_Transmit_DMA(&huart1,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum);
        //HAL_UART_Transmit_DMA(&huart1,&sendtestBufDMA[2],1);
        //HAL_UART_Transmit_IT(&huart1,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum);
        //HAL_UART_Transmit_IT(&huart1,&DMA_NDTR,2);
      }
	}
	else if(huart->Instance==huart1.Instance)
	{
		//(void)huart->Instance->SR;//????IDLE??,???????,??????NUM!=SIZE????IDLE
		//(void)huart->Instance->DR;
		//__HAL_UART_CLEAR_IDLEFLAG(huart);
		//HAL_UART_DMAStop(huart);
		Uart1DMAData.rxBufNum = UART1DMA_RXBUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx); //?????UARTDMA_RXBUFFER_SIZE
		Uart1DMAData.rxFlag=1;
		HAL_UART_Receive_DMA(&huart1, Uart1DMAData.rxDMABuf, UART1DMA_RXBUFFER_SIZE);
		if(InsertQueue(&USART1_Software_FIFO,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum)==false)
		{
			//HAL_GPIO_TogglePin(USER_LED_GPIO_Port,USER_LED_Pin);
		}
	}
	if(huart->Instance==huart4.Instance)
	{
      
      HAL_UART_Receive_DMA(&huart4,Uart4DMABuffer,UART4DMA_RXBUFFER_SIZE);
			
      
      {//debug
        //HAL_GPIO_WritePin(USER_LED2_GPIO_Port,USER_LED2_Pin,1);//??
        //HAL_GPIO_TogglePin(USER_LED2_GPIO_Port,USER_LED2_Pin);
        //HAL_UART_Transmit_DMA(&huart1,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum);
        //HAL_UART_Transmit_DMA(&huart1,&sendtestBufDMA[2],1);
        //HAL_UART_Transmit_IT(&huart1,Uart1DMAData.rxDMABuf,Uart1DMAData.rxBufNum);
        //HAL_UART_Transmit_IT(&huart1,&DMA_NDTR,2);
      }
	}
}
/* USER CODE END 1 */
