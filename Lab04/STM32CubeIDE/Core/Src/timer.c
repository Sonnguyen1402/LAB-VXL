/*
 * timer.c
 *
 *  Created on: Oct 5, 2022
 *      Author: ngtha
 */


#include "main.h"
#include "timer.h"
#include "input_reading.h"

int TIME_CYCLE = 10;

int timerBlinking_counter = 0;
int timerBlinking_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

void setTimerBlinking(int duration){
	timerBlinking_counter = duration / TIME_CYCLE;
	timerBlinking_flag = 0;
}

void setTimer1(int duration){
	timer1_counter = duration / TIME_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration / TIME_CYCLE;
	timer2_flag = 0;
}

int getTimerBlinkingFlag(){
	if (timerBlinking_flag == 1){
		timerBlinking_flag = 0;
		return 1;
	}
	return 0;
}

int getTimer1Flag(){
	if (timer1_flag == 1){
		timer1_flag = 0;
		return 1;
	}
	return 0;
}

int getTimer2Flag(){
	if (timer2_flag == 1){
		timer2_flag = 0;
		return 1;
	}
	return 0;
}

void timerRun(){
	if (timerBlinking_counter > 0){
		timerBlinking_counter--;
		if (timerBlinking_counter <= 0){
			timerBlinking_flag = 1;
		}
	}

	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <= 0){
			timer2_flag = 1;
		}
	}
}
