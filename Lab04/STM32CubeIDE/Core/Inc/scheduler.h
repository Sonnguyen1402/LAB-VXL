/*
 * scheduler.h
 *
 *  Created on: Nov 8, 2022
 *      Author: ngtha
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "stdint.h"
#include "main.h"

typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint32_t TaskID;
} sTask;

//#define SCH_MAX_TASKS 40

#define MAX_NUMBER_OF_TASK 40

void Leds_Init();
void SCH_Init();
void SCH_Update(void);
void SCH_Dispatch_Tasks(UART_HandleTypeDef *huart1);
uint32_t SCH_Delete_Task (uint32_t TaskID);
uint32_t SCH_Add_Task (void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD);

#endif /* INC_SCHEDULER_H_ */
