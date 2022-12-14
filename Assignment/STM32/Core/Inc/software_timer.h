/*
 * software_timer.h
 *
 *  Created on: Dec 6, 2022
 *      Author: ngtha
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

int getTimerBlinkingFlag();
int getTimer1Flag();
int getTimer2Flag();
int getTimer3Flag();

void setTimerBlinking(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
