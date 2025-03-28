/*
* UART_Bluetooth.c
*
* Created: 2025-03-06 오후 12:36:45
* Author : USER
*/

#include "device/def.h"

//ISR(USART0_RX_vect)
//{
	//UART_ISR_Process();
//}


int main(void)
{
	Init();
	UART_print("HC-05 Test Start \r\n");
	while (1)
	{
		unsigned char data = UART_Receive();
		UART_Transmit(data);
		
		//if(UART_execute())
		//{
			//uint8_t *rxString = UART_readRxBuff();
			//
			//UART_print(rxString);
			//
			//LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
			//LCD_GotoXY(i%2,0);
			//LCD_WriteString(rxString);
			//
			//if (rxString[1] == '\n' || rxString[1] == '\0' || rxString[1] == '\r')  // 한 글자만 들어온 경우 (다음 값이 '\0'으로 알았지만 '\n' 이였다.)
			//{
				//Controller(rxString[0]);
			//}
			//
			//i++;
		//}
	}
}

void Init()
{
	UART_Init();
	LEDInit();
	FNDInit();
	FANInit();
	LCD_Init();
}

void Controller(char str)
{
	//UART_Transmit('C');  // UART_Controller가 호출되었는지 확인
	//UART_Transmit(str);  // 들어온 문자 확인
	//UART_Transmit('\n');
	
	if(str == '0')
	{
		LEDOff();
		FNDOff();
		FANOff();
	}
	else if(str == '1')
	{
		LEDToggle();
	}
	else if(str == '2')
	{
		FNDStepUp();
	}
	else if(str == '3')
	{
		FANToggle();
	}
	else if(str == 'c')
	{
		LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	}
	else return;
}
