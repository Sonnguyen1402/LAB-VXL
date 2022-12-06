/*
 * led_processing.h
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#ifndef INC_LED_PROCESSING_H_
#define INC_LED_PROCESSING_H_

void updateTrafficLED(int trafficLed0, int trafficLed1);
void toggleTrafficLed(int trafficLed0, int trafficLed1);
void displayPedestrianLed(int pedestrianLed);
//void SEG_display();
//void update7SEG(int index7SEG, int counter0, int counter1);

#endif /* INC_LED_PROCESSING_H_ */
