/*
 * Keypad.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Eng_Fawzi
 */

#include "Dio.h"
#include "Keypad_Types.h"

u8 Keypad_layout[4][4]=
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
};

void Keypad_vidInit(void)
{
	/*	Configure Rows Pins as input	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN0, DIO_INPUT);/* ROW0	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN1, DIO_INPUT);/* ROW1	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN2, DIO_INPUT);/* ROW2	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN3, DIO_INPUT);/* ROW3 */

	/*	Configure Columns Pins as output	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);/*	COL0 */
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN5, DIO_OUTPUT);/* COL1 */
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN6, DIO_OUTPUT);/* COL2 */
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN7, DIO_OUTPUT);/* COL3 */

	Dio_vidPullUpEn(DIO_PORTC, DIO_PIN0);
	Dio_vidPullUpEn(DIO_PORTC, DIO_PIN1);
	Dio_vidPullUpEn(DIO_PORTC, DIO_PIN2);
	Dio_vidPullUpEn(DIO_PORTC, DIO_PIN3);


	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);
}

static boolean Keypad_IsPressed(void)
{
	if (
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN0) == DIO_LOW ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN1) == DIO_LOW ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN2) == DIO_LOW ||
			Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) == DIO_LOW
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


static kp_row_t Keypad_GetRow(void)
{
	kp_row_t loc_ButtonRow = KP_NOROW;
	if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN0) == DIO_LOW)
	{
		loc_ButtonRow = KP_ROW0;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN1) == DIO_LOW)
	{
		loc_ButtonRow = KP_ROW1;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN2) == DIO_LOW)
	{
		loc_ButtonRow = KP_ROW2;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) == DIO_LOW)
	{
		loc_ButtonRow = KP_ROW3;
	}
	else
	{
		loc_ButtonRow = KP_NOROW;
	}
	return loc_ButtonRow;
}

static kp_col_t Keypad_GetCol(kp_row_t current_row)
{
	kp_col_t loc_ButtonCol = KP_NOCOL;

	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);

	if (Keypad_GetRow() == current_row)
	{
		loc_ButtonCol = KP_COL0;
	}
	else
	{
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_HIGH);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);

		if (Keypad_GetRow() == current_row)
		{
			loc_ButtonCol = KP_COL1;
		}
		else
		{
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_HIGH);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);

			if (Keypad_GetRow() == current_row)
			{
				loc_ButtonCol = KP_COL2;
			}
			else
			{
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);

				if (Keypad_GetRow() == current_row)
				{
					loc_ButtonCol = KP_COL3;
				}
				else
				{
					loc_ButtonCol = KP_NOCOL;
				}
			}
		}
	}
	return loc_ButtonCol;
}

u8 Keypad_u8GetKey(void)
{
	u8 loc_key = 0xFF;
	kp_row_t loc_Row = KP_NOROW;
	kp_row_t loc_Col = KP_NOCOL;

	Keypad_vidInit();
	/*	Check If Keypad Pressed*/
	if (Keypad_IsPressed() == TRUE)
	{
		/*	Get pressed key ROW*/
		loc_Row = Keypad_GetRow();
		/*	Get pressed key COLUMN	*/
		loc_Col = Keypad_GetCol(loc_Row);
		/* loc_key = Keypad_layout[ROW][COLUMN]	*/
		loc_key = Keypad_layout[loc_Row][loc_Col];
	}
	else
	{
		/*	Do Nothing	*/
		loc_key = 0xFF;
	}
	return loc_key;
}
