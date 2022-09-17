/*
 * Dc_Motor.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_
#define SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_

#include "Dc_Motor_Types.h"

void Dc_Motor_vidInit(void);
void Dc_Motor_vidStart(motor_dir_t dir);
void Dc_Motor_vidStop(void);



#endif /* SOURCE_02_ECUA_DC_MOTOR_INC_DC_MOTOR_H_ */
