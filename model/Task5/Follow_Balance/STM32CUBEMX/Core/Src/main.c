/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "ifr-scope_device.h"
#include "ws2812.h"
#include "StackLiteDualDrive.h"
#include "rtwtypes.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern volatile uint32_t simulinkRunFlag[2];
uint32_t simulinkOverrunCount= 0;
//When the step funtion runs out of cycle time, simulinkRunFlag>1, and simulinkOverrunCount will increase.

extern int16_t HI226_Angle[3];
extern int16_t HI226_AngleV[3];
extern uint16_t adc_rawvalue[2][5];
volatile uint16_t adc1_DMAData[10]= { 0 };

volatile uint16_t adc2_DMAData[10]= { 0 };

extern UartDMADataTypeDef Uart1DMAData;
uint8_t Uart3DMABuffer[UART3DMA_RXBUFFER_SIZE]= { 0 };
uint8_t Uart4DMABuffer[UART4DMA_RXBUFFER_SIZE]= { 0 };//V1.2 add

int32_t time2_enc[2]= { 0 };

int32_t time5_enc[2]= { 0 };

int32_t motor1_speed= 0;
int32_t motor2_speed= 0;
unsigned int time_5ms_count= 0;
int16_t motor1_PwmData= 0;
int16_t motor2_PwmData= 0;
uint8_t led_data= 0;
uint8_t ws2812_data[3]= { 192,40,198 };
uint16_t pwm4_1_DMAData[WS2812_NUMS*3*8+1]={0};
uint16_t pwm4_2_DMAData[WS2812_NUMS*3*8+1]={0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static inline void simulinkInputRefresh(void);
static inline void simulinkOutputProcess(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int32_t adcrunfreq[2]={0};
extern uint16_t HI226_FreqCount;
uint16_t HI226_Freq=0;
extern int32_t RPi_SendData[4];//V1.2 add
void timer_5ms_callback(void)
{
  time_5ms_count++;
  if (time_5ms_count%200==0) {
	  adcrunfreq[0]=simulinkRunFlag[0];
	  adcrunfreq[1]=simulinkRunFlag[1];
	  simulinkRunFlag[0]= 0;
	  simulinkRunFlag[1]= 0;
	  HI226_Freq= HI226_FreqCount;
	  HI226_FreqCount=0;
    //HAL_GPIO_TogglePin(USER_LED_GPIO_Port,USER_LED_Pin);
  }

  if (time_5ms_count%2==0) {
    time2_enc[0]= (int32_t)(__HAL_TIM_GetCounter(&htim2));
    time5_enc[0]= (int32_t)(__HAL_TIM_GetCounter(&htim5));
    motor1_speed= time5_enc[0]-time5_enc[1];
    motor2_speed= time2_enc[0]-time2_enc[1];
    time5_enc[1]= time5_enc[0];
    time2_enc[1]= time2_enc[0];
	  
	//UpdateOneColorToAllBit(ws2812_data,pwm4_1_DMAData,WS2812_NUMS);//G R B ,pwm4_1 Close to SWD interface, this rgb is handed back to the IFR-Scope for status management
	UpdateOneColorToAllBit(ws2812_data,pwm4_2_DMAData,WS2812_NUMS);
	HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_1,(uint32_t*)pwm4_1_DMAData,WS2812_NUMS*24+1);/* start DMA transfer on TIM4 channel 1 */
	HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_2,(uint32_t*)pwm4_2_DMAData,WS2812_NUMS*24+1);/* start DMA transfer on TIM4 channel 2 */
	  
	RPi_DataSend(RPi_SendData);//V1.2 add
  }
  IFR_Scope_Main();
}

static inline void simulinkInputRefresh(void)
{
  //__disable_irq();  /* Disable global interrupt, Access to the critical zone*/

  //__enable_irq();    /*  Enable global interrupt */
}

static inline void simulinkOutputProcess(void)
{
  motor1_PwmData= motor1_PwmData>4200?4200:motor1_PwmData;
  motor1_PwmData= motor1_PwmData<-4200?-4200:motor1_PwmData;
  if (motor1_PwmData>0)                //forward T9C1(IN1)=1 T9C2(IN2)=0
  {                                    //low decay
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 4200);
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 4200-motor1_PwmData);
  } else {
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 4200);
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 4200+motor1_PwmData);
  }

  motor2_PwmData= motor2_PwmData>4200?4200:motor2_PwmData;
  motor2_PwmData= motor2_PwmData<-4200?-4200:motor2_PwmData;
  if (motor2_PwmData>0)                //forward T9C1(IN1)=1 T9C2(IN2)=0
  {                                    //low decay
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_2, 4200);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_1, 4200-motor2_PwmData);
  } else {
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_1, 4200);
    __HAL_TIM_SetCompare(&htim8, TIM_CHANNEL_2, 4200+motor2_PwmData);
  }

  //	if(motor1_PwmData>0)	//forward T9C1(IN1)=1 T9C2(IN2)=0
  //	{//fast decay
  //		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0);
  //		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, motor1_PwmData);
  //	}
  //	else
  //	{
  //		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
  //		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, -motor1_PwmData);
  //	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_UART5_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_UART4_Init();
  MX_TIM7_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  /* USER CODE BEGIN 2 */
  __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);						//Open ESP8266_UART IDLE IT
  HAL_UART_Receive_DMA(&huart1, Uart1DMAData.rxDMABuf, UART1DMA_RXBUFFER_SIZE);
  __HAL_UART_ENABLE_IT(&huart3,UART_IT_IDLE);	//OPEN HI226_UART IDLE
	HAL_UART_Receive_DMA(&huart3,Uart3DMABuffer,UART3DMA_RXBUFFER_SIZE);//Start DMA at main
  __HAL_UART_ENABLE_IT(&huart4,UART_IT_IDLE);	//OPEN RPi UART IDLE //V1.2 add
	HAL_UART_Receive_DMA(&huart4,Uart4DMABuffer,UART4DMA_RXBUFFER_SIZE); //V1.2 add
	
  //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);	//no dma test
  //HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_2);
  __HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_1,0);//6->0;13->13231
  __HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_2,0);//6->0;13->1
  
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,0);//0->0v;100->3.3v
  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_2,0);//0->0v;100->3.3v
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_2);
  __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_1,0);//0->0v;100->3.3v
  __HAL_TIM_SetCompare(&htim8,TIM_CHANNEL_2,0);//0->0v;100->3.3v
  __HAL_TIM_SetCounter(&htim3,0);//Synchronisation
  __HAL_TIM_SetCounter(&htim8,0);
  HAL_ADC_Start_DMA(&hadc1,(uint32_t *)adc1_DMAData,10);
  HAL_ADC_Start_DMA(&hadc2,(uint32_t *)adc2_DMAData,10);
  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_ALL);
  HAL_Delay(10);
  USER_ADC_Zero_calibration();
//pwmdma_testinit();
  HAL_TIM_Base_Start_IT(&htim7);//5 ms time trigger

  //HAL_UART_Receive_DMA(&huart3,Uart3DMABuffer,UART3DMA_RXBUFFER_SIZE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  StackLiteDualDrive_initialize();
  //HAL_UART_Transmit_DMA(&huart4, "mcu test", 8);//test
  while (1) {
    //HAL_Delay(10);
	//HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_1,(uint32_t*)pwm4_1_DMAData,2*24+1);/* nabling DMA transfer on TIM1 channel 1 */
	//HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_2,(uint32_t*)pwm4_2_DMAData,2*24+1);/* nabling DMA transfer on TIM1 channel 1 */
	//HAL_DMA_Start(htim4.hdma[TIM_DMA_ID_CC1], (uint32_t)pwm4_1_DMAData, (uint32_t)htim4.Instance->CCR1,2*24+1);
	//HAL_DMA_Start(htim4.hdma[TIM_DMA_ID_CC2], (uint32_t)pwm4_2_DMAData, (uint32_t)htim4.Instance->CCR2,2*24+1);
	//__HAL_TIM_ENABLE_DMA(&htim4, TIM_DMA_CC1);
	//__HAL_TIM_ENABLE_DMA(&htim4, TIM_DMA_CC2);
	//TIM_CCxChannelCmd(htim4.Instance, TIM_CHANNEL_1, TIM_CCx_ENABLE);
	//TIM_CCxChannelCmd(htim4.Instance, TIM_CHANNEL_2, TIM_CCx_ENABLE);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    if (simulinkRunFlag[0]>0&&simulinkRunFlag[1]>0) {
      if (simulinkRunFlag[0]>1||simulinkRunFlag[1]>1)//step funtion run time end
      {
        simulinkOverrunCount++;
                      //when step time for start to end more than 0.1ms, count++
      }

      simulinkRunFlag[0]= 0;           //step funtion run time start
      simulinkRunFlag[1]= 0;           //step funtion run time start
      simulinkInputRefresh();
      StackLiteDualDrive_step();
      simulinkOutputProcess();
    }
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1) {
  }

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
