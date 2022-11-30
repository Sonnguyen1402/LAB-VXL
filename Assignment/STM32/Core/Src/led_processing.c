/*
 * led_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "main.h"
#include "led_processing.h"



void updateTrafficLED(int trafficLed0, int trafficLed1){
	switch (trafficLed0){
	case 0:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		break;
	default:
		break;
	}
	switch (trafficLed1){
	case 0:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
	default:
		break;
	}
}

void manual_processing (){
	if (trafficLed0 == 0){
		trafficLed0 = 1;

		setTimer2(2000);
	}
}
/*
void toggleTrafficLed(int trafficLed0, int trafficLed1){
	switch (trafficLed0){
	case 0:
		HAL_GPIO_TogglePin(GPIOB, LED_RED_0_Pin);
		HAL_GPIO_WritePin (GPIOB, LED_GREEN_0_Pin, SET);
		HAL_GPIO_WritePin (GPIOB, LED_YELLOW_0_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED_RED_0_Pin, SET);
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN_0_Pin);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_0_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_RED_0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_0_Pin, SET);
		HAL_GPIO_TogglePin(GPIOB, LED_YELLOW_0_Pin);
		break;
	default:
		break;
	}
	switch (trafficLed1){
	case 0:
		HAL_GPIO_TogglePin(GPIOB, LED_RED_1_Pin);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN_1_Pin);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_1_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
		HAL_GPIO_TogglePin(GPIOB, LED_YELLOW_1_Pin);
		break;
	default:
		break;
	}
}*/
