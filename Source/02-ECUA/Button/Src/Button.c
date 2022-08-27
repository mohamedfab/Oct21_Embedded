/*
 * Button.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Eng_Fawzi
 */
#include "Button.h"
#include "Dio.h"

void Button_vidbuttonInit(void)
{
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN0, DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTD, DIO_PIN6, DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTD, DIO_PIN2, DIO_INPUT);
}


button_butStatus_t Button_udtbuttonStatus(button_buttonId_t butnId)
{
	button_butStatus_t locBtnStatus = RELAEASED;
	switch (butnId)
	{
		case BUTTON0:
			if (Dio_udtreadChanel(DIO_PORTB, DIO_PIN0) == DIO_HIGH)
			{
				locBtnStatus = PRESSED;
			}
			else
			{
				locBtnStatus = RELAEASED;
			}
			break;

		case BUTTON1:
			if (Dio_udtreadChanel(DIO_PORTD, DIO_PIN6) == DIO_HIGH)
			{
				locBtnStatus = PRESSED;
			}
			else
			{
				locBtnStatus = RELAEASED;
			}
			break;

		case BUTTON2:
			if (Dio_udtreadChanel(DIO_PORTD, DIO_PIN2) == DIO_HIGH)
			{
				locBtnStatus = PRESSED;
			}
			else
			{
				locBtnStatus = RELAEASED;
			}
			break;
	}
	return locBtnStatus;
}

