/*
 * timer.h
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */
#include "main.h"

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void setTimer0 (int );
void setTimer1 (int );

int getTimer0Flag ( void );
int getTimer1Flag ( void );

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef *);

void stopTimer0 ();

void timer_run ( void );

#endif /* INC_TIMER_H_ */
