/*
 * led_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "main.h"
#include "led_processing.h"

static int value = 0 ;

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

void increase7SegLED () {
	display7SEG_0(value++);
	if (value >= 10) value = 0;
}




//////////////////////////////////////////////////////////////////////////////


void toggleLED1 () {
	HAL_GPIO_TogglePin (GPIOB, LED_0_Pin);
}

void toggleLED2 () {
	HAL_GPIO_TogglePin (GPIOB, LED_1_Pin);
}

void toggleLED3 () {
	HAL_GPIO_TogglePin (GPIOB, LED_2_Pin);
}

void toggleLED4 () {
	HAL_GPIO_TogglePin (GPIOB, LED_3_Pin);
}

void toggleLED5 () {
	HAL_GPIO_TogglePin (GPIOB, LED_4_Pin);
}

