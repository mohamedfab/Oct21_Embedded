/*
 * ExtInt_Types.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_
#define SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}extint_id_t;

typedef enum
{
	EXT_FAILING_EDGE,
	EXT_RISING_EDGE,
	EXT_BOTH_EDGE,
	EXT_LOW_LEVEL
}extint_sensectrl_t;




#endif /* SOURCE_01_MCAL_EXTINT_INC_EXTINT_TYPES_H_ */
