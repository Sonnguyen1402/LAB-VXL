/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define LED_BLINKING_Pin GPIO_PIN_0
#define LED_BLINKING_GPIO_Port GPIOA
#define LED7_0_0_Pin GPIO_PIN_1
#define LED7_0_0_GPIO_Port GPIOA
#define LED7_0_1_Pin GPIO_PIN_2
#define LED7_0_1_GPIO_Port GPIOA
#define LED7_0_2_Pin GPIO_PIN_3
#define LED7_0_2_GPIO_Port GPIOA
#define LED7_0_3_Pin GPIO_PIN_4
#define LED7_0_3_GPIO_Port GPIOA
#define LED7_0_4_Pin GPIO_PIN_5
#define LED7_0_4_GPIO_Port GPIOA
#define LED7_0_5_Pin GPIO_PIN_6
#define LED7_0_5_GPIO_Port GPIOA
#define LED7_0_6_Pin GPIO_PIN_7
#define LED7_0_6_GPIO_Port GPIOA
#define LED_RED_0_Pin GPIO_PIN_0
#define LED_RED_0_GPIO_Port GPIOB
#define LED_GREEN_0_Pin GPIO_PIN_1
#define LED_GREEN_0_GPIO_Port GPIOB
#define LED_YELLOW_0_Pin GPIO_PIN_2
#define LED_YELLOW_0_GPIO_Port GPIOB
#define BUTTON_0_Pin GPIO_PIN_13
#define BUTTON_0_GPIO_Port GPIOB
#define BUTTON_1_Pin GPIO_PIN_14
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_15
#define BUTTON_2_GPIO_Port GPIOB
#define LED7_1_0_Pin GPIO_PIN_8
#define LED7_1_0_GPIO_Port GPIOA
#define LED7_1_1_Pin GPIO_PIN_9
#define LED7_1_1_GPIO_Port GPIOA
#define LED7_1_2_Pin GPIO_PIN_10
#define LED7_1_2_GPIO_Port GPIOA
#define LED7_1_3_Pin GPIO_PIN_11
#define LED7_1_3_GPIO_Port GPIOA
#define LED7_1_4_Pin GPIO_PIN_12
#define LED7_1_4_GPIO_Port GPIOA
#define LED7_1_5_Pin GPIO_PIN_13
#define LED7_1_5_GPIO_Port GPIOA
#define LED7_1_6_Pin GPIO_PIN_14
#define LED7_1_6_GPIO_Port GPIOA
#define LED_RED_1_Pin GPIO_PIN_3
#define LED_RED_1_GPIO_Port GPIOB
#define LED_GREEN_2_Pin GPIO_PIN_4
#define LED_GREEN_2_GPIO_Port GPIOB
#define LED_YELLOW_1_Pin GPIO_PIN_5
#define LED_YELLOW_1_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
