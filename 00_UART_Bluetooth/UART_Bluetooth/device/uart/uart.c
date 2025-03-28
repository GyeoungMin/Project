/*
* uart.c
*
* Created: 2025-03-06 오후 12:42:22
*  Author: USER
*/

#include "uart.h"

uint8_t rxBuff[100];
uint8_t rxFlag;

uint8_t UART_getFlag()
{
	return rxFlag;
}

void UART_clearRxFlag()
{
	rxFlag = 0;
}

void UART_setReadyRxFlag()
{
	rxFlag = 1;
}

uint8_t *UART_readRxBuff()
{
	return rxBuff;
}

void UART_Init()
{
	UBRR0H = UART_BAUD_H;
	UBRR0L = UART_BAUD_L;
	
	// 2배속, 8비트, 패리티x, 스톱비트 1개
	UCSR0A |= (1<<U2X0);
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
	//UCSR0B |= (1<<RXCIE0); // | (1<<TXCIE0);
	
	sei();
}

void UART_Transmit(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

unsigned char UART_Receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
} 

void UART_print(char *str)
{
	for(int i = 0; str[i]; i++)
	{
		UART_Transmit(str[i]);
	}
	UART_Transmit('\n');
}

uint8_t UART_avail()
{
	if(!(UCSR0A & (1<<RXC0)))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void UART_ISR_Process()
{
	uint8_t rxData = UDR0;
	
	static uint8_t rxHead = 0;
	if(rxData == '\n')
	{
		rxBuff[rxHead] = rxData;
		rxHead++;
		rxBuff[rxHead] = '\0';
		rxHead = 0;
		UART_setReadyRxFlag();
	}
	else
	{
		rxBuff[rxHead] = rxData;
		rxHead++;
	}
}

uint8_t UART_execute()
{
	if(UART_getFlag())
	{
		UART_clearRxFlag();
		return 1;
	}
	
	_delay_ms(300);
	return 0;
}


