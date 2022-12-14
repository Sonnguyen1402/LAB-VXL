/*
 * uart_communicating.c
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */

#include "command_parser.h"
#include "uart_communicating.h"
#include "timer.h"
#include "main.h"

#include "stdio.h"

#define PERIOD_FOR_RESEND 3000

enum UART {
	WAITTING_RST,
	WAITTING_OK,
	SEND_REP
};

// Array use for printing response
char buffer_uart[20];
enum UART uart_state = WAITTING_RST;

uint32_t adc_value = 0;

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

void uart_communication_fsm(){
	switch (uart_state){
	case WAITTING_RST:
		// Received command "!RST#"
		if(isCommandRST()){
			adc_value = HAL_ADC_GetValue(&hadc1);
			// Change state
			uart_state = SEND_REP;
		}
		break;
	case SEND_REP:
		// Send packet
		HAL_UART_Transmit(&huart2, (void *)buffer_uart, sprintf(buffer_uart, "\r\n!ADC=%lu#", adc_value), 200);
		// Change state
		uart_state = WAITTING_OK;
		setTimer0(PERIOD_FOR_RESEND);
		break;
	case WAITTING_OK:
		// Received command "!OK#"
		if(isCommandOK()){
			stopTimer0();
			uart_state = WAITTING_RST;
			HAL_UART_Transmit (&huart2, (void *)buffer_uart, sprintf(buffer_uart, "\r\n"), 200);
		}
		// Waiting for "!OK#" in 3s
		if(getTimer0Flag() == 1){
			uart_state = SEND_REP;
		}
		break;
	default:
		break;
	}
}
