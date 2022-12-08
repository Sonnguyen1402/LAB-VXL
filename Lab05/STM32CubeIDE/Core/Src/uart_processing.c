/*
 * uart_processing.c
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */

#include "uart_processing.h"
#include "main.h"

#define MAX_SIZE 30
uint8_t temp = 0;
uint8_t buffer [MAX_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

extern UART_HandleTypeDef huart2;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart -> Instance == USART2) {
		buffer [index_buffer++] = temp;
		if(index_buffer >= MAX_SIZE) index_buffer = 0;

		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
		// Display character have just entered
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
	}
}

uint8_t getBufferFlag () {
	return buffer_flag;
}

void resetBufferFlag () {
	buffer_flag = 0;
}

uint8_t getChar () {
	return temp;
}
