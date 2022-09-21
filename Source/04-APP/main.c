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

u8 glb_uartRx = 0;

ISR(USART_RXC_vect)
{
	 glb_uartRx = UART_UDR_REG;

	if (glb_uartRx == 'b')
	{
		Led_vidledToggle(LED1);
	}
	else if (glb_uartRx == 'a')
	{
		Led_vidledToggle(LED0);
	}
}

int main()
{
	USART_Init(9600);
	USART_Receive_InterruptEnable();
	GINT_vidEnableAllInterrupts();
	Led_vidinit();
	USART_TransmitStr("Hello UART....");

while (1)
	{
		Led_vidledToggle(LED2);
		_delay_ms(500);
	}
	return 0;
}
