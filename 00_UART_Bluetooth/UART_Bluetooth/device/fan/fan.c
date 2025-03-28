/*
 * fan.c
 *
 * Created: 2025-03-06 오후 12:40:38
 *  Author: USER
 */ 

#include "fan.h"

void FANInit()
{
	FAN_DDR = (1<<7);
	FAN_PORT = 0x00;
}

void FANToggle()
{
	FAN_PORT ^= (1<<7);
}

void FANOff()
{
	FAN_PORT = 0x00;
}