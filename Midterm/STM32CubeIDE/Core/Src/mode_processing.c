/*
 * mode_processing.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "global.h"
#include "mode_processing.h"

void mode_processing(){
	switch(mode){
	case 1:
		if (initState == 0){
			trafficLed0 = 0; // turn red
			trafficLed1 = 1; // turn green
			counter0 = timeDurations[trafficLed0]; // get red timeduration
			counter1 = timeDurations[trafficLed1]; // get red timeduration
			initState = 1;
			updateTrafficLED(trafficLed0, trafficLed1);
			setTimer1(1000);
		}
		else {
			if (getTimer1Flag() == 1){
				counter0--;
				counter1--;
				if (counter0 <= 0){
					trafficLed0++;
					if (trafficLed0 >= 3)
						trafficLed0 = 0;
					counter0 = timeDurations[trafficLed0];
				}
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
			trafficLed1 = 0;
			timeTemp = timeDurations[trafficLed0];
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
		counter0 = timeTemp;
		counter1 = mode;
		break;
	case 3:
		if (initState == 0){
			trafficLed0 = 1;
			trafficLed1 = 1;
			timeTemp = timeDurations[trafficLed0];
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
		counter0 = timeTemp;
		counter1 = mode;
		break;
	case 4:
		if (initState == 0){
			trafficLed0 = 2;
			trafficLed1 = 2;
			timeTemp = timeDurations[trafficLed0];
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
		counter0 = timeTemp;
		counter1 = mode;
		break;
	}
}
