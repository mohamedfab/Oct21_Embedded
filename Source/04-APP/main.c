/***************************************
 * main.c
 * Created on: Aug 23, 2022
 * Author: Eng_Fawzi
 ***************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "Led.h"
#include "Button.h"


int main()
{
	Led_vidinit();
	Button_vidbuttonInit();

	while (1)
	{
		if (Button_udtbuttonStatus(BUTTON0) == PRESSED)
		{
			Led_vidledOn(LED0);
			_delay_ms(500);
			Led_vidledOff(LED0);
			_delay_ms(500);
		}
	}
	return 0;
}
