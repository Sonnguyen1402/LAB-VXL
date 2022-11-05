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
					counter = 0;
					break;
				case 1:
					buttonpressed = 1;
					initState = 1;
					if (counter >= 9) counter = 0;
					else counter++;
					break;
				case 2:
					buttonpressed = 1;
					initState = 1;
					if (counter <= 0) counter = 9;
					else counter--;
					break;
				default:
					break;
				}
			}
			//buttonpressed = 0;
			//pressed3sec = 0;
			break ;
		case BUTTON_PRESSED :
			if (!is_button_pressed(i)){
				buttonState[i] = BUTTON_RELEASED;
				buttonpressed = 0;
				pressed3sec = 0;
			}
			else {
				if( is_button_pressed_1s (i)){
					buttonState [i] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(i)){
				buttonState [i] = BUTTON_RELEASED;
				buttonpressed = 0;
				pressed3sec = 0;
			}
			switch (i){
			case 0:
				break;
			case 1:
				pressed3sec = 1;
				break;
			case 2:
				pressed3sec = 2;
				break;
			default:
				//pressed3sec = 0;
				break;
			}
			break;
		default:
			break;
		}
	}
}
