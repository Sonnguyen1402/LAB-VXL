/*
 * uart_processing.h
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */
#include "main.h"

#ifndef INC_UART_PROCESSING_H_
#define INC_UART_PROCESSING_H_

// Uart interrupt function
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
// Get buffer_flag when received character from terminal
uint8_t getBufferFlag();
// Set buffer_flag = 0
void resetBufferFlag();
// Get character received from terminal
uint8_t getChar();
extern uint8_t temp;

#endif /* INC_UART_PROCESSING_H_ */
