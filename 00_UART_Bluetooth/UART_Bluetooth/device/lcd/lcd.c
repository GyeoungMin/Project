#include "lcd.h"

void LCD_Data(uint8_t data)
{
	LCD_DATA_PORT = data;
}

void LCD_WritePin()
{
	LCD_RW_PORT &= ~(1<<LCD_RW);	// RW핀을 LOW로 설정해서 쓰기모드 진입
}

void LCD_EnablePin()				// 동작에 대한 트리거
{
	LCD_E_PORT &= ~(1<<LCD_E);		// 우선 로우로 설정
	LCD_E_PORT |= (1<<LCD_E);		// E핀 액티브 하이 (실제 동작)
	LCD_E_PORT &= ~(1<<LCD_E);		// 다시 로우로 내림
	_delay_us(1600);				// 시간이 모자르면 동작 안함 (1600us 이상)
}

void LCD_WriteCommand(uint8_t commandData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS);	// RS핀을 LOW로 설정 명령어 모드
	LCD_WritePin();					// 데이터 쓰기 모드 진입
	LCD_Data(commandData);			// 명령어를 데이터 핀에 출력
	LCD_EnablePin();				// LCD 동작 신호 전송
}

void LCD_WriteData(uint8_t charData)
{
	LCD_RS_PORT |= (1<<LCD_RS);		// RS핀을 HIGH로 설정 데이터 모드로 진입
	LCD_WritePin();
	LCD_Data(charData);
	LCD_EnablePin();
}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;						// col을 16으로 제한
	row %= 2;						// row를 2로 제한
	uint8_t address = (0x40 * row) + col;	// 주소 계산
	uint8_t command = 0x80 + address;		// 주소 설정
	LCD_WriteCommand(command);
}

void LCD_WriteString(char *string)
{
	for(uint8_t i = 2; string[i]; i++)
	{
		LCD_WriteData(string[i-2]);
	}
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row, col);
	LCD_WriteString(string);
}

void LCD_Init()
{
	LCD_DATA_DDR = 0xff;
	LCD_RS_DDR |= (1<<LCD_RS);
	LCD_RW_DDR |= (1<<LCD_RW);
	LCD_E_DDR |= (1<<LCD_E);
	
	_delay_ms(20);
	LCD_WriteCommand(COMMAND_8BIT_MODE);
	_delay_ms(5);
	LCD_WriteCommand(COMMAND_8BIT_MODE);
	_delay_ms(5);
	LCD_WriteCommand(COMMAND_8BIT_MODE);
	LCD_WriteCommand(COMMAND_8BIT_MODE);
	
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
}