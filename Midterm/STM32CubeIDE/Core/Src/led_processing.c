/*
 * led_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "main.h"
#include "led_processing.h"

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
