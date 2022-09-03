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

int main()
{
	u8 key =00;
	s8 counter =0;
	u16 i=0;
	Button_vidbuttonInit();
	SSD_vidinit();
	while (1)
	{
		key = Keypad_u8GetKey();
		if (key != 0xFF)
		{

		}
		SSD_viddisplyNum(counter);
		if (Button_udtbuttonStatus(BUTTON0) == PRESSED)
		{

//			SSD_viddelayWithDisplay_ms(counter, 250);

			while (Button_udtbuttonStatus(BUTTON0) == PRESSED)
				SSD_viddisplyNum(counter);

			counter++;
			if (counter == 100)
			{
				counter =0;
			}
		}

		if (Button_udtbuttonStatus(BUTTON2) == PRESSED)
			{
				SSD_viddelayWithDisplay_ms(counter, 250);
				counter--;
				if (counter == -1)
				{
					counter = 99;
				}
			}
	}
	return 0;
}
