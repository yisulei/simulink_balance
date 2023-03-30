/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "arm_math.h."
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_KEY_Pin GPIO_PIN_13
#define USER_KEY_GPIO_Port GPIOC
#define USER_LED_Pin GPIO_PIN_14
#define USER_LED_GPIO_Port GPIOC
#define E1_T5C1_Pin GPIO_PIN_0
#define E1_T5C1_GPIO_Port GPIOA
#define E1_T5C2_Pin GPIO_PIN_1
#define E1_T5C2_GPIO_Port GPIOA
#define E2_T2C1_Pin GPIO_PIN_15
#define E2_T2C1_GPIO_Port GPIOA
#define E2_T2C2_Pin GPIO_PIN_3
#define E2_T2C2_GPIO_Port GPIOB
#define WS2812_T4C1_Pin GPIO_PIN_6
#define WS2812_T4C1_GPIO_Port GPIOB
#define WS2812_T4C2_Pin GPIO_PIN_7
#define WS2812_T4C2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
