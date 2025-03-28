/*
 * def.h
 *
 * Created: 2025-03-06 오후 12:38:37
 *  Author: USER
 */ 


#ifndef DEF_H_
#define DEF_H_

#define F_CPU 16000000UL
#define BAUD 38400

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define FAN_DDR DDRB
#define FAN_PORT PORTB

#define FND_DDR DDRA
#define FND_PORT PORTA

#define LED_DDR DDRC
#define LED_PORT PORTC

#define UART_BAUD_H 1>>8
#define UART_BAUD_L ((F_CPU / (16UL * BAUD)) - 1)

#include "fan/fan.h"
#include "fnd/fnd.h"
#include "led/led.h"
#include "uart/uart.h"
#include "lcd/lcd.h"

void Init();
void Controller(char str);

#endif /* DEF_H_ */