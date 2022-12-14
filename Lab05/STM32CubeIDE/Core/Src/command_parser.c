/*
 * command_processing.c
 *
 *  Created on: Dec 8, 2022
 *      Author: ngtha
 */


#include "command_parser.h"
#include "uart_processing.h"
#include "main.h"

enum CMD {
	BEGIN,
	EXCLAMATION_POINT,
	R_CHARACTER,
	S_CHARACTER,
	T_CHARACTER,
	O_CHARACTER,
	K_CHARACTER,
	RECEIVED_RST,
	RECEIVED_OK
};

enum CMD command_state = BEGIN;

void command_parser_fsm() {
	switch (command_state) {
	case BEGIN:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		break;
	case EXCLAMATION_POINT:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 82) {
			command_state = R_CHARACTER;
		}
		else if(getChar() == 79) {
			command_state = O_CHARACTER;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case R_CHARACTER:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 83) {
			command_state = S_CHARACTER;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case S_CHARACTER:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 84) {
			command_state = T_CHARACTER;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case T_CHARACTER:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 35) {
			command_state = RECEIVED_RST;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case O_CHARACTER:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 75) {
			command_state = K_CHARACTER;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case K_CHARACTER:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else if(getChar() == 35) {
			command_state = RECEIVED_OK;
		}
		else {
			command_state = BEGIN;
		}
		break;
	case RECEIVED_RST:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else command_state = BEGIN;
		break;
	case RECEIVED_OK:
		if(getChar() == 33) {
			command_state = EXCLAMATION_POINT;
		}
		else command_state = BEGIN;
		break;
	default:
		break;
	}
}

uint8_t isCommandRST()
{
	if (command_state == RECEIVED_RST)
		return 1;
	return 0;
}

uint8_t isCommandOK()
{
	if (command_state == RECEIVED_OK)
		return 1;
	return 0;
}
