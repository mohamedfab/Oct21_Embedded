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


#define EXTINT_GICR_REG			(*(u8*)0x5B)
#define EXTINT_MCUCR_REG		(*(u8*)0x55)
#define EXTINT_MCUCR_REG		(*(u8*)0x55)

ISR(INT0_vect)
{
	Led_vidledToggle(LED1);
}

int main()
{
	GINT_vidEnableAllInterrupts();

	/*	Enable External INT0	*/
	SET_BIT(EXTINT_GICR_REG,6);

	/*	Configure Sense Control	*/
	SET_BIT(EXTINT_MCUCR_REG,0);
	SET_BIT(EXTINT_MCUCR_REG,1);

	while (1)
	{

	}
	return 0;
}
