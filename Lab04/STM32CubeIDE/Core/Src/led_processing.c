/*
 * led_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "main.h"
#include "led_processing.h"

void display7SEG_0 ( int num ){
	switch ( num ){
		case 0:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_5_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_6_Pin, SET );
			break;
		case 1:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_5_Pin | LED7_0_6_Pin, SET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_1_Pin | LED7_0_2_Pin, RESET );
			break;
		case 2:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_2_Pin | LED7_0_5_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_4_Pin | LED7_0_5_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_3_Pin | LED7_0_4_Pin, SET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_1_Pin | LED7_0_2_Pin | LED7_0_5_Pin | LED7_0_6_Pin, RESET );
			break;
		case 5:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_5_Pin | LED7_0_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_1_Pin | LED7_0_4_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_5_Pin | LED7_0_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_1_Pin, SET );
			break;
		case 7:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_2_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_5_Pin | LED7_0_6_Pin, SET );
			break;
		case 8:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_4_Pin | LED7_0_5_Pin | LED7_0_6_Pin, RESET );
		break;
		case 9:
			HAL_GPIO_WritePin (GPIOA, LED7_0_0_Pin | LED7_0_1_Pin | LED7_0_2_Pin | LED7_0_3_Pin | LED7_0_5_Pin | LED7_0_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_0_4_Pin, SET );
			break;
		default:
			break;
	}
}

void display7SEG_1 ( int num ){
	switch ( num ){
		case 0:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_5_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_6_Pin, SET );
			break;
		case 1:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_5_Pin | LED7_1_6_Pin, SET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_1_Pin | LED7_1_2_Pin, RESET );
			break;
		case 2:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_2_Pin | LED7_1_5_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_4_Pin | LED7_1_5_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_3_Pin | LED7_1_4_Pin, SET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_1_Pin | LED7_1_2_Pin | LED7_1_5_Pin | LED7_1_6_Pin, RESET );
			break;
		case 5:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_5_Pin | LED7_1_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_1_Pin | LED7_1_4_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_5_Pin | LED7_1_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_1_Pin, SET );
			break;
		case 7:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_2_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_5_Pin | LED7_1_6_Pin, SET );
			break;
		case 8:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_4_Pin | LED7_1_5_Pin | LED7_1_6_Pin, RESET );
		break;
		case 9:
			HAL_GPIO_WritePin (GPIOA, LED7_1_0_Pin | LED7_1_1_Pin | LED7_1_2_Pin | LED7_1_3_Pin | LED7_1_5_Pin | LED7_1_6_Pin, RESET );
			HAL_GPIO_WritePin (GPIOA, LED7_1_4_Pin, SET );
			break;
		default:
			break;
	}
}

void updateTrafficLED(int trafficLed0, int trafficLed1){
	switch (trafficLed0){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED_RED_0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_0_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED_RED_0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_0_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_RED_0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_0_Pin, RESET);
		break;
	default:
		break;
	}
	switch (trafficLed1){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_1_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_1_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, LED_YELLOW_1_Pin, RESET);
		break;
	default:
		break;
	}
}

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
}

void update7SEG(int index, int counter_0, int counter_1){
	switch(index){
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin (GPIOB, EN0_Pin | EN2_Pin, RESET );
			HAL_GPIO_WritePin (GPIOB, EN1_Pin | EN3_Pin, SET);
			//display7SEG(led_buffer[0]);
			display7SEG_0(counter_0 % 10);
			display7SEG_1(counter_1 % 10);
			break;
		case 1:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin (GPIOB, EN0_Pin | EN2_Pin, SET );
			HAL_GPIO_WritePin (GPIOB, EN1_Pin | EN3_Pin, RESET);
			//display7SEG(led_buffer[0]);
			display7SEG_0(counter_0 / 10);
			display7SEG_1(counter_1 / 10);
			break;
		default:
			break;
	}
}
