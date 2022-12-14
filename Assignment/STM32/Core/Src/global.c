/*
 * global.c
 *
 *  Created on: Oct 26, 2022
 *      Author: ngtha
 */

#include "main.h"

int mode = 0;

int timeDurations[3] = {7, 4, 3}; // red, green, yellow time

int initState = 0;

int trafficLed0 = 0;
int trafficLed1 = 0;

int counter0 = 0;
int counter1 = 0;

int index7SEG = 0;

int timeBlinking = 500;

int duration = 0;

int pedestrian = 0;
int timeCycle = 0;
