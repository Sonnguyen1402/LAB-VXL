/*
 * timer.c
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */


#include "timer.h"
#include "main.h"

#define TIMER_CYCLE 10

static int timer0_counter = 0;
static int timer1_counter = 0;
static int timer0_flat = 0;
static int timer1_flat = 0;

void setTimer0 (int duration ) {
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flat = 0;
}
void setTimer1 (int duration) {
	timer1_counter = duration / TIMER_CYCLE ;
	timer1_flat = 0;
}
void timer_run(){
	if( timer0_counter > 0) {
		timer0_counter--;
		if( timer0_counter == 0) timer0_flat = 1;
	}
	if( timer1_counter > 0) {
		timer1_counter--;
		if( timer1_counter == 0) timer1_flat = 1;
	}
}

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim){
	if( htim -> Instance == TIM2 ) {
		timer_run();
	}
}

int getTimer0Flag(){
	return timer0_flat;
}

int getTimer1Flag(){
	return timer1_flat;
}

void stopTimer0(){
	timer0_counter = 0;
	timer0_flat = 0;
}
