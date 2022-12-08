/*
 * command_processing.h
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */

#include "main.h"

#ifndef INC_COMMAND_PROCESSING_H_
#define INC_COMMAND_PROCESSING_H_

// Finite state machine for command processing
void command_parse_fsm();
// Get state which received "!RST#"
uint8_t isCommandRST();
// Get state which received "!OK#"
uint8_t isCommandOK();

#endif /* INC_COMMAND_PROCESSING_H_ */
