/*
 * ExtInt.h
 *
 *  Created on: Sep 3, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_EXTINT_INC_EXTINT_H_
#define SOURCE_01_MCAL_EXTINT_INC_EXTINT_H_

#include "ExtInt_Types.h"

#define INT0_EN_BIT			(6)
#define INT1_EN_BIT			(7)
#define INT2_EN_BIT			(5)


void ExtInt_vidConfigExtInt(extint_id_t intId, extint_sensectrl_t sensCtrl);
void ExtInt_vidDisableExtInt(extint_id_t intId);

#endif /* SOURCE_01_MCAL_EXTINT_INC_EXTINT_H_ */
