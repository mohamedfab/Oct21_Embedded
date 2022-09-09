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




int main()
{
	u16 result;
	f64 volt =0;
	u8 voltDisplay = 0;

	Adc_vidInit();
	Lcd_vidinit();
	Lcd_vidCmd(_LCD_CURSOR_OFF);



	while (1)
	{

		result = Adc_u16AdcRead(ADC_CHANNEL1);

		volt = result * (f64)4.8; /*	mv	*/
		volt = volt/10;			/*	v	*/

		voltDisplay = volt * 10;
		//3.6 * 10 = 36

		Lcd_vidRowColumn(0, 0);
		Lcd_vidDisplyStr("Volt =    ");
		Lcd_vidRowColumn(0, 6);
		Lcd_vidDisplyInt(voltDisplay/10);
		Lcd_vidDisplayChar('.');
		Lcd_vidDisplyInt(voltDisplay%10);
		_delay_ms(100);
	}
	return 0;
}
