/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2022
 *      Author: ngtha
 */
#include "stddef.h"
#include "scheduler.h"
#include "main.h"

#define TIMER_CYCLE 10
sTask SCH_task_array[MAX_NUMBER_OF_TASK];

static int minDelayCounter = -1;
static int minDelay = -1;

uint8_t tBuffer[50]={"Executed Task PID =     at tick              \r\n"};
#define PID_index 			19
#define PID_length 			3
#define tick_index 			26
#define tick_length 		12

void updateBuffer(int tid, int tick) {
	for (int i=0;  i< PID_length;i++) {
		tBuffer[PID_length + PID_index - i] = tid%10+48;
		tid/=10;
	}

	for (int i = 0; i < tick_length; i++) {
		tBuffer[tick_length + tick_index - i] = tick%10+48;
		tick/=10;
	}
}


void Leds_Init(void) {
	// Init LED
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, SET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, SET);
}

void SCH_Init(){
	for (int i = 0; i <MAX_NUMBER_OF_TASK; i++) {
		SCH_task_array[i].pTask = NULL;
		SCH_task_array[i].Delay = 0;
		SCH_task_array[i].Period = 0;
		SCH_task_array[i].TaskID = 0;
	}
}

void SCH_Update () {
	minDelayCounter--;
}

uint32_t SCH_Add_Task (void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	int i = 0 ;
	// Find empty slot
	while ((SCH_task_array [i].pTask != 0 ) && (i < MAX_NUMBER_OF_TASK)) {
		i++;
	}
	// Array is full
	if( i >= MAX_NUMBER_OF_TASK) {
		return MAX_NUMBER_OF_TASK;
	}
	// Add task
	SCH_task_array[i].pTask = pFunction;
	SCH_task_array[i].Delay = DELAY / TIMER_CYCLE;
	SCH_task_array[i].Period = PERIOD / TIMER_CYCLE;
	SCH_task_array[i].TaskID = i;

	// initiate minDelay
	if (minDelay < 0) {
		minDelayCounter = SCH_task_array[i].Delay;
		minDelay = SCH_task_array[i].Delay;
	}
	// new task’s delay is smaller than minDelayCounter
	else if (minDelay >= 0 && SCH_task_array[i].Delay < minDelayCounter) {
		// timeDelayed is time the all other tasks have waited
		int timeDelayed = minDelay - minDelayCounter;
		if (timeDelayed > 0) {
			// Update delay of all tasks
			for (int i = 0; i < MAX_NUMBER_OF_TASK; i++) {
				if (SCH_task_array[i].pTask != 0) {
					SCH_task_array[i].Delay -= timeDelayed;
				}
			}
		}
		minDelay = SCH_task_array[i].Delay;
		minDelayCounter = SCH_task_array[i].Delay;
	}
	return i;
}

#define RETURN_NORMAL 	0
#define RETURN_ERROR  	1

uint32_t SCH_Delete_Task ( uint32_t taskID ) {
	uint32_t returnCode = -1 ;
	if (SCH_task_array[taskID].pTask == 0) {
		returnCode = RETURN_ERROR; // Not finished
	}
	else {
		returnCode = RETURN_NORMAL; // Not finished
	}
	SCH_task_array[taskID].pTask = 0 ;
	SCH_task_array[taskID].Delay = 0 ;
	SCH_task_array[taskID].Period = 0 ;

	return returnCode;
}


void SCH_Dispatch_Tasks(UART_HandleTypeDef *huart1){
	if (minDelayCounter == 0) {
		int tempDelay = minDelay;
		// Reset minDelay
		minDelay = -1;

		for ( int i = 0 ; i < MAX_NUMBER_OF_TASK; i++) {
			if ( SCH_task_array[i].pTask != 0 ) {
				// Update delay of all tasks
				SCH_task_array[i].Delay = SCH_task_array[i].Delay - tempDelay ;
				// Execute task
				if (SCH_task_array[i].Delay == 0) {
						(*SCH_task_array[i].pTask) ();
						updateBuffer(SCH_task_array[i].TaskID, HAL_GetTick());
						HAL_UART_Transmit(huart1, tBuffer, 50, 100);
					// Task executes one time
					if (SCH_task_array[i].Period == 0 ) {
						SCH_Delete_Task(i);
						continue;
					}
					// Task has period
					else {
						SCH_task_array[i].Delay = SCH_task_array[i].Period;
					}
				}
				// initiated minDelay
				if (minDelay < 0) {
					minDelayCounter = SCH_task_array[i].Delay;
					minDelay = SCH_task_array[i].Delay;
				}
				// get new minDelay if task's delay is smaller
				else {
					if ( SCH_task_array[i].Delay < minDelay ) {
						minDelayCounter = SCH_task_array[i].Delay;
						minDelay = SCH_task_array[i].Delay;
					}
				}
			}
		}
	}
}


