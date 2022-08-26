/***************************************
 * main.c
 * Created on: Aug 23, 2022
 * Author: Eng_Fawzi
 ***************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>

#include "Dio.h"

#define LED0			(2)
#define BUTTON0			(0)

int main()
{
//	SET_BIT(DDRC_REG,LED0);	/*	configure PinC2 as output	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);

//	CLEAR_BIT(DDRB_REG,BUTTON0);

	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN0, DIO_INPUT);

	while (1)
	{
//		 if(CHECK_BIT(PINB_REG,BUTTON0) == 1)
//		 {
//			SET_BIT(PORTC_REG,LED0);	/*	Turn ON LED */
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
			_delay_ms(500);			/*	wait	*/
//			CLEAR_BIT(PORTC_REG,LED0);	/*	Turn OFF LED	*/
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN2, DIO_LOW);
			_delay_ms(500);			/*	wait	*/
//		 }
	 }
	return 0;
}
