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
void timer_run ( void );
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef *);
int getTimer0Flag ( void );
int getTimer1Flag ( void );
void stopTimer0 ();

#endif /* INC_TIMER_H_ */
