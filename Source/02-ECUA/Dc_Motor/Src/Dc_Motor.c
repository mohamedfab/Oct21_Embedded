/*
 * Dc_Motor.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Eng_Fawzi
 */


#include "Dc_Motor.h"
#include "util/delay.h"

void Dc_Motor_vidInit(void)
{
	/*	Configure Motor Control Pins as Outputs	*/

	/*	Make Sure Motor is Stop	*/

}
void Dc_Motor_vidStart(motor_dir_t dir)
{
	if (dir == DIR_CW)
	{
		/*	Set IN1 Pin	*/

		/*	Clear IN2 Pin	*/

	}
	else
	{
		/*	Clear IN1 Pin	*/

		/*	Set IN2 Pin	*/

	}

	/*	Set EN1 Pin	*/

}
void Dc_Motor_vidStop(void)
{
	/*	Clear EN1 Pin	*/

	/*	Wait Till Motor Stop	*/
	_delay_ms(3000);
}
