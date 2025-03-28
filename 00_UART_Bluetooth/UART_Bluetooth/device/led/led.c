/*
 * led.c
 *
 * Created: 2025-03-06 오후 12:41:18
 *  Author: USER
 */ 

#include "led.h"

void LEDInit()
{
	LED_DDR = 0xFF;
	LED_PORT = 0xFF;
}

void LEDToggle()
{
	LED_PORT ^= 0xFF;
}

void LEDOff()
{
	LED_PORT = 0x00;
}