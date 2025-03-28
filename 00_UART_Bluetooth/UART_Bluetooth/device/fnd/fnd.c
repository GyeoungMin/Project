/*
* fnd.c
*
* Created: 2025-03-06 오후 12:40:48
*  Author: USER
*/

#include "fnd.h"

uint8_t current_step = 0;

uint8_t FND_Number[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6D, 0x7D, 0x27, 0x7f, 0x67};

void FNDInit()
{
	FND_DDR = 0xFF;
	FND_PORT = FND_Number[current_step];
}

void FNDStepUp()
{
	current_step++;
	if(current_step == 10)
	{
		current_step = 0;
	}
	FND_PORT = FND_Number[current_step];
}

void FNDOff()
{
	FND_PORT = 0x00;
}