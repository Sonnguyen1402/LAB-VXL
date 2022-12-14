/*
 * uart_processing.h
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */
#include "main.h"

#ifndef INC_UART_PROCESSING_H_
#define INC_UART_PROCESSING_H_

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
uint8_t getBufferFlag();
void resetBufferFlag();
uint8_t getChar();
extern uint8_t temp;

#endif /* INC_UART_PROCESSING_H_ */
