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
while (1)
	{
		Led_vidledToggle(LED2);
		_delay_ms(500);
	}
	return 0;
}
