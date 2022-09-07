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


ISR(INT0_vect)
{
	Led_vidledToggle(LED1);
}

int main()
{
	Led_vidinit();
	GINT_vidEnableAllInterrupts();
	ExtInt_vidConfigExtInt(EXT_INT0, EXT_RISING_EDGE);
	while (1)
	{
		Led_vidledToggle(LED0);
		_delay_ms(500);
	}
	return 0;
}
