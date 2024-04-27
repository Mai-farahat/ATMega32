/*
 * main.c
 *
 * Created: 07/02/2024 7:40:40 AM
 *  Author: MAI
 */ 
#include "ECUAL/LCD/LCD.h"
// EXample
uint8_t bell[8] = {0x04, 0x0E, 0X0E, 0X0E, 0X1F, 0X00, 0X04, 0X00};
void LCD_createCustomcharacter(uint8_t *pattern, uint8_t location)
{
	uint8_t i = 0;
	LCD_8_bit_sendCommand(0X40 + (location * 8));
	for(i = 0; i < 8; i++)
	{
		LCD_8_bit_sendChar(pattern[i]);
	}
}
int main(void)
{
	LCD_8_bit_init();
	LCD_createCustomcharacter(bell , 0);
	while(1){
		
		LCD_8_bit_sendChar(0);
		
	}
}





























































