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


/*	ADC Registers	*/
#define ADC_ADMUX_REG       (*(u8*)0x27)
#define ADC_ADCSRA_REG		(*(u8*)0x26)
#define ADC_ADCH_REG		(*(u8*)0x25)
#define ADC_ADCL_REG		(*(u8*)0x24)



ISR(INT0_vect)
{
	Led_vidledToggle(LED1);
}

int main()
{
	u16 result;
	f64 volt =0;
	Lcd_vidinit();
	/*	Enable ADC	*/
	SET_BIT(ADC_ADCSRA_REG, 7);
	/*	Configure ADC prescaler	 /128	*/
	ADC_ADCSRA_REG |= 7 /*0000 0111*/;
	/*	Select Vref +	AVCC	*/
	SET_BIT(ADC_ADMUX_REG,6);
	/*	select ADC channel	*/
	ADC_ADMUX_REG |= 1/*00001*/;

	while (1)
	{
		/*	Start ADC conversion	*/
		SET_BIT(ADC_ADCSRA_REG,6);
		/*	wait until ADIF flag become 1 */
		while(CHECK_BIT(ADC_ADCSRA_REG,4) !=1)
		{
			/*	Do Nothing	*/
		}
		/*	clear ADIF by writing 1 	*/
		SET_BIT(ADC_ADCSRA_REG,4);
		/*	read ADC result form ADCL, ADCH	*/
		result=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));

		volt = result * (f64)4.8;
		volt = volt/1000;

		Lcd_vidRowColumn(0, 0);
		Lcd_vidDisplyStr("    ");
		Lcd_vidRowColumn(0, 0);
		Lcd_vidDisplyFlot(volt);
		_delay_ms(100);
	}
	return 0;
}
