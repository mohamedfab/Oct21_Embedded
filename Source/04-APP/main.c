/***************************************
 * main.c
 *
 *  Created on: Aug 23, 2022
 *  Author: Eng_Fawzi
 ***************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "Led.h"
#include "SSD.h"
#include "Lcd.h"
#include <stdio.h>
#include "Button.h"
#include "GINT.h"
#include <avr/interrupt.h>
#include "ExtInt.h"
#include "Adc.h"
#include "Lm35.h"
#include "Uart.h"

int main()
{
	USART_Init(9600);
	USART_TransmitStr("Hello Uart...");
while (1)
	{

	}
	return 0;
}
