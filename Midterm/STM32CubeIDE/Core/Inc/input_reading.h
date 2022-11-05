/*
 * input_reading.h
 *
 *  Created on: Oct 5, 2022
 *      Author: ngtha
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define NO_OF_BUTTONS 3

void button_reading ( void );
unsigned char is_button_pressed (unsigned char index);
unsigned char is_button_pressed_3s (unsigned char index);

#endif /* INC_INPUT_READING_H_ */
