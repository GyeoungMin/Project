/*
 * uart.h
 *
 * Created: 2025-03-06 오후 12:42:31
 *  Author: USER
 */ 


#ifndef UART_H_
#define UART_H_

#include "../def.h"

void UART_Init();
uint8_t UART_getFlag();
void UART_clearRxFlag();
void UART_setReadyRxFlag();
uint8_t *UART_readRxBuff();
void UART_Transmit(unsigned char data);
unsigned char UART_Receive(void);
void UART_print(char *str);
uint8_t UART_avail();
void UART_ISR_Process();
uint8_t UART_execute();

#endif /* UART_H_ */