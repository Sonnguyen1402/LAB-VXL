/*
 * input_processing.c
 *
 *  Created on: Oct 5, 2022
 *      Author: ngtha
 */

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "global.h"
#include "timer.h"

enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_3_SECOND };
enum ButtonState buttonState[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

void fsm_simple_buttons_run (){
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++){
		switch ( buttonState[i]){
		case BUTTON_RELEASED:
			if( is_button_pressed(i)){
				buttonState [i] = BUTTON_PRESSED;
				setTimer1(10000); //setTimer 10s for auto_processing in section 2.4
				switch (i){
				case 0: //Reset button
					counter = 0;
					break;
				case 1: //INC button
					if (counter >= 9) counter = 0;
					else counter++;
					break;
				case 2: //DEC button
					if (counter <= 0) counter = 9;
					else counter--;
					break;
				default:
					break;
				}
			}
			break ;
		case BUTTON_PRESSED :
			if (!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
			}
			else {
				if( is_button_pressed_3s (i)){
					buttonState [i] = BUTTON_PRESSED_MORE_THAN_3_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_3_SECOND:
			if (!is_button_pressed(i)){
				buttonState [i] = BUTTON_RELEASED;
			}
			setTimer1(10000); //setTimer 10s for auto_processing in section 2.4
			break;
		default:
			break;
		}
	}
}

void auto_processing(){
	if (getTimer1Flag() == 1){
		if (counter >= 0) {
			counter--;
			setTimer1(1000);
		}
	}
}
// This function check if button INC/DEC is long pressed then processing depend on each button.
void fsm_3s_long_pressed(){
	if (is_button_pressed_3s(1) == 0 && is_button_pressed_3s(2) == 0){
		setTimer2(1000);
	}
	else {
		if (getTimer2Flag() == 1){
			if (is_button_pressed_3s(1) == 1){
				if (counter >= 9) counter = 0;
				else counter++;
			}
			else if (is_button_pressed_3s(2) == 1){
				if (counter <= 0) counter = 9;
				else counter--;
			}
			setTimer2(1000);
		}
	}
}
