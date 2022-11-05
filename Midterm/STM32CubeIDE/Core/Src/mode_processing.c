/*
 * mode_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "global.h"
#include "mode_processing.h"
#include "timer.h"
#include "input_reading.h"

void auto_processing(){
	if (getTimer1Flag() == 1){
		if (counter >= 0) counter--;
		setTimer1(1000);
	}
}

void pressed3sec_processing(){
	if (is_button_pressed_1s(1) == 0 && is_button_pressed_1s(2) == 0){
		setTimer2(1000);
	}
	else {
		if (getTimer2Flag() == 1){
			if (is_button_pressed_1s(1) == 1){
				if (counter >= 9) counter = 0;
				else counter++;
			}
			else if (is_button_pressed_1s(2) == 1){
				if (counter <= 0) counter = 9;
				else counter--;
			}
			setTimer2(1000);
		}
	}
}
