/*
 * command_processing.h
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */

#include "main.h"

#ifndef INC_COMMAND_PROCESSING_H_
#define INC_COMMAND_PROCESSING_H_

void command_parser_fsm();
uint8_t isCommandRST();
uint8_t isCommandOK();

#endif /* INC_COMMAND_PROCESSING_H_ */
