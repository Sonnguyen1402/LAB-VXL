/*
 * mode_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "global.h"
#include "mode_processing.h"
#include "led_processing.h"
#include "timer.h"

void mode_processing(){
	switch(mode){
	case 1: // Mode 01: The traffic light application is running normally.
		if (initState == 0){
			trafficLed0 = 0; // turn on red led on road 01
			trafficLed1 = 1; // turn on green led on road 02
			counter0 = timeDurations[trafficLed0]; // set red time duration for counter
			counter1 = timeDurations[trafficLed1]; // set green time duration for counter
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1); // display Traffic LED on both roads
			setTimer1(1000);
		}
		else {
			if (getTimer1Flag() == 1){
				counter0--;
				counter1--;
				// update led 01 to next color
				if (counter0 <= 0){
					trafficLed0++;
					if (trafficLed0 >= 3)
						trafficLed0 = 0;
					counter0 = timeDurations[trafficLed0];
				}
				// update led 02 to next color
				if (counter1 <= 0){
					trafficLed1++;
					if (trafficLed1 >= 3)
						trafficLed1 = 0;
					counter1 = timeDurations[trafficLed1];
				}
				updateTrafficLED(trafficLed0, trafficLed1);
				setTimer1(1000);
			}
		}
		break;
	case 2:
		if (initState == 0){
			trafficLed0 = 0;
			trafficLed1 = 1;
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1);
			//setTimer1(10000);
		}
		else {
			if (getTimer1Flag() == 1){
				mode = 1;
				initState = 0;
			}
		}
		updateTrafficLED(trafficLed0, trafficLed1);
		break;
	case 3: // Mode 2 - Modify time duration for the red LEDs
		if (initState == 0){
			trafficLed0 = 0;
			trafficLed1 = 0;
			duration = timeDurations[trafficLed0];
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1);
			setTimer1(timeBlinking);
		}
		else {
			if( getTimer1Flag() == 1){
				toggleTrafficLed(trafficLed0, trafficLed1);
				setTimer1 (timeBlinking);
			}
		}
		counter0 = duration;
		counter1 = mode;
		break;
	case 4: // Mode 3 - Modify time duration for the amber LEDs
		if (initState == 0){
			trafficLed0 = 2;
			trafficLed1 = 2;
			duration = timeDurations[trafficLed0];
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1);
			setTimer1(timeBlinking);
		}
		else {
			if( getTimer1Flag() == 1){
				toggleTrafficLed(trafficLed0, trafficLed1);
				setTimer1 (timeBlinking);
			}
		}
		counter0 = duration;
		counter1 = mode;
		break;
	case 5: // Mode 4 - Modify time duration for the green LEDs
		if (initState == 0){
			trafficLed0 = 1;
			trafficLed1 = 1;
			duration = timeDurations[trafficLed0];
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1);
			setTimer1(timeBlinking);
		}
		else {
			if( getTimer1Flag() == 1){
				toggleTrafficLed(trafficLed0, trafficLed1);
				setTimer1 (timeBlinking);
			}
		}
		counter0 = duration;
		counter1 = mode;
		break;
	}
}
