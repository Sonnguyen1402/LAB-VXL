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
					if (mode >= 5) mode = 1;
					else mode++;
					break;
				case 1: // Button 2
					if (mode == 2) {
						setTimer1(10000);

						if (trafficLed0 >= 2) trafficLed0 = 0;
						else trafficLed0++;
						if (trafficLed1 >= 2) trafficLed1 = 0;
						else trafficLed1++;
					}
					if (mode >= 3 && mode < 6) {
						if (duration >= 99) duration = 1;
						else duration++;
					}
					break;
				case 2: // Button 3: set duration
					if (mode == 3) timeDurations[0] = duration;
					else if (mode == 4) timeDurations[2] = duration;
					else if (mode == 5) timeDurations[1] = duration;
					break;
				case 3: // Button 4: pedestrian
					mode == 10;
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
