/*
 * timer.h
 *
 *  Created on: Oct 5, 2022
 *      Author: ngtha
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

//extern int timerBlinking_flag;
//extern int timer1_flag;
//extern int timer2_flag;

int getTimerBlinkingFlag();
int getTimer1Flag();
int getTimer2Flag();

void setTimerBlinking(int duration);
void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

#endif /* INC_TIMER_H_ */
