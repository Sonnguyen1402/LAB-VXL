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

enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND };
enum ButtonState buttonState[NO_OF_BUTTONS] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};

void fsm_for_input_processing ( void ){
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++){
		switch ( buttonState[i]){
		case BUTTON_RELEASED:
			if( is_button_pressed(i)){
				buttonState [i] = BUTTON_PRESSED;
				switch (i){
				case 0:
					initState = 0;
					if (mode >= 4) mode = 1;
					else mode++;
					break;
				case 1:
					if (mode <= 1) break;
					if (timeTemp >= 99) timeTemp = 1;
					else timeTemp++;
					break;
				case 2:
					if (mode >= 2){
						timeDurations[mode - 2] = timeTemp;
						//mode = 1;
					}
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
				if( is_button_pressed_1s (i)){
					buttonState [i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
			// This case in this exercise is not used
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed (i)){
				buttonState [i] = BUTTON_RELEASED;
			}
			switch (i){
			case 0:
				//timeTemp = 69;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
