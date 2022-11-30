/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2022
 *      Author: ngtha
 */
#include "stddef.h"
#include "main.h"
#include "scheduler.h"

typedef struct {
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

#define NO_TASK_ID	0

#define ERROR_SCH_CANNOT_DELETE_TASK	1
#define RETURN_NORMAL 	0
#define RETURN_ERROR  	1

static sTask SCH_tasks_G[MAX_NUMBER_OF_TASK];
static unsigned char Error_code_G = 0;

uint8_t tBuffer[50]={"Execute Task:      at tick              \r\n"};
uint8_t tBuffer2[50]={"Delete Task:      at tick              \r\n"};
#define PID_index 			13
#define PID_length 			3
#define tick_index 			26
#define tick_length 		12


void updateBuffer(int pid, int tick, int type) {
	if (type == 0) {
		for (int i=0;  i< PID_length;i++) {
			tBuffer[PID_length + PID_index - i] = pid%10+48;
			pid/=10;
		}

		for (int i = 0; i < tick_length; i++) {
			tBuffer[tick_length + tick_index - i] = tick%10+48;
			tick/=10;
		}
	}
	else if (type == 1) {
		for (int i=0;  i< PID_length;i++) {
			tBuffer2[PID_length + PID_index - i] = pid%10+48;
			pid/=10;
		}

		for (int i = 0; i < tick_length; i++) {
			tBuffer2[tick_length + tick_index - i] = tick%10+48;
			tick/=10;
		}
	}
}


void SCH_Update( void ) {
	for (unsigned char Index = 0; Index < MAX_NUMBER_OF_TASK; Index++) {
		// Check if there is a task at the Index
		if (SCH_tasks_G [Index].pTask) {
			if (SCH_tasks_G[Index].Delay == 0) {
				// Increase RunMe flag for run task later
				SCH_tasks_G[Index].RunMe++;
				if (SCH_tasks_G[Index].Period) {
					// Schedule periodic tasks to run again
					SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period ;
				}
			} else {
				SCH_tasks_G[Index].Delay--;

			}
		}
	}
}

uint32_t SCH_Add_Task (void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD)
{
	unsigned char Index = 0;
	// Scan for empty slot
	while (( SCH_tasks_G[Index].pTask != 0) && ( Index < MAX_NUMBER_OF_TASK))
	{
		Index++;
	}
	if (Index == MAX_NUMBER_OF_TASK)
	{
		return MAX_NUMBER_OF_TASK;
	}

	SCH_tasks_G[Index].pTask 	= pFunction ;
	SCH_tasks_G[Index].Delay 	= DELAY;
	SCH_tasks_G[Index].Period 	= PERIOD;
	SCH_tasks_G[Index].RunMe 	= 0 ;

	return SCH_tasks_G[Index].TaskID;
}

void SCH_Dispatch_Tasks(UART_HandleTypeDef *huart1 )
{
	unsigned char Index ;

	for (Index = 0; Index < MAX_NUMBER_OF_TASK; Index++) {
		if (SCH_tasks_G[Index].RunMe > 0) {
			(*SCH_tasks_G[Index].pTask)() ; // Run the task
			SCH_tasks_G[Index].RunMe--; // Reset RunMe flag

			updateBuffer(SCH_tasks_G[Index].TaskID, HAL_GetTick(), 0); // Add Task ID with tick
			HAL_UART_Transmit(huart1, tBuffer, 50, 100); // Print Task ID with tick via UART

			if (SCH_tasks_G[Index].Period == 0) // Delete task which has Period = 0
			{
				SCH_Delete_Task(Index);
				updateBuffer(SCH_tasks_G[Index].TaskID, HAL_GetTick(), 1); // Add Task ID with tick
				HAL_UART_Transmit(huart1, tBuffer2, 50, 100); // Print Task ID with tick via UART
			}
		}
	}
}


uint32_t SCH_Delete_Task (uint32_t TaskID) {
	unsigned char TASK_INDEX = -1;
	// Scan for Task ID
	for (unsigned char Index = 0; Index < MAX_NUMBER_OF_TASK; Index++){
		if (SCH_tasks_G[Index].TaskID == TaskID) {
			TASK_INDEX = Index;
			break;
		}
	}
	// Index not found
	if (TASK_INDEX == -1) {
		return RETURN_ERROR;
	}

	unsigned char Return_code;
	// Delete Task
	if (SCH_tasks_G[TASK_INDEX].pTask == 0) {
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		Return_code = RETURN_ERROR;
	} else {
		Return_code = RETURN_NORMAL;
	}

	SCH_tasks_G[TASK_INDEX].pTask 	= 0x0000 ;
	SCH_tasks_G[TASK_INDEX].Delay 	= 0;
	SCH_tasks_G[TASK_INDEX].Period 	= 0;
	SCH_tasks_G[TASK_INDEX].RunMe 	= 0;

	return Return_code;
}


void SCH_Init ( void ) {
	// Assign Index
	for (unsigned char Index = 0; Index < MAX_NUMBER_OF_TASK; Index++){
		SCH_tasks_G[Index].TaskID = Index;
	}

	unsigned char i ;
	// Empty all slot
	for (i = 0 ; i < MAX_NUMBER_OF_TASK; i ++) {
		SCH_Delete_Task(i);
	}

	Error_code_G = 0;
}

void LEDs_Init(void) {
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, SET);
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, SET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
}

