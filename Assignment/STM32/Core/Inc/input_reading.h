/*
 * input_reading.h
 *
 *  Created on: Oct 5, 2022
 *      Author: ngtha
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

// we aim to work with more than one buttons
#define NO_OF_BUTTONS 4

void button_reading ( void );
unsigned char is_button_pressed (unsigned char index);
unsigned char is_button_pressed_1s (unsigned char index);

#endif /* INC_INPUT_READING_H_ */
