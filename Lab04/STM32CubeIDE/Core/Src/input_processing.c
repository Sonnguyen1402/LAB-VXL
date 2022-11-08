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
				case 0: // Button 1: increase Mode
					initState = 0;
					if (mode >= 4) mode = 1;
					else mode++;
					break;
				case 1: // Button 2: increase duration
					if (mode <= 1) break;
					if (duration >= 99) duration = 1;
					else duration++;
					break;
				case 2: // Button 3: set duration
					if (mode == 2) timeDurations[0] = duration;
					else if (mode == 3) timeDurations[2] = duration;
					else if (mode == 4) timeDurations[1] = duration;
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
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed (i)){
				buttonState [i] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
		}
	}
}
