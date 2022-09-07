/*
 * ExtInt.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Eng_Fawzi
 */

#include "Bit_Math.h"
#include "ExtInt_Types.h"
#include "ExtInt_Reg.h"
#include "ExtInt.h"
#include "Std_Types.h"

void ExtInt_vidConfigExtInt(extint_id_t intId, extint_sensectrl_t sensCtrl)
{
	switch(intId)
	{
	case EXT_INT0:
		/*	configure sense control	*/
		if (sensCtrl == EXT_RISING_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG,0);
			SET_BIT(EXTINT_MCUCR_REG,1);
		}
		else if (sensCtrl == EXT_FAILING_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			SET_BIT(EXTINT_MCUCR_REG,1);
		}
		else if (sensCtrl == EXT_BOTH_EDGE)
		{
			SET_BIT(EXTINT_MCUCR_REG,0);
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
		}
		else if (sensCtrl == EXT_LOW_LEVEL)
		{
			CLEAR_BIT(EXTINT_MCUCR_REG,0);
			CLEAR_BIT(EXTINT_MCUCR_REG,1);
		}
		else
		{
			/*	Do Nothing	*/
		}
		/*	Enable Int0 Interrupt	*/
		SET_BIT(EXTINT_GICR_REG,INT0_EN_BIT);
		break;

	case EXT_INT1:

		/*	configure sense control	*/
				if (sensCtrl == EXT_RISING_EDGE)
				{
					SET_BIT(EXTINT_MCUCR_REG,2);
					SET_BIT(EXTINT_MCUCR_REG,3);
				}
				else if (sensCtrl == EXT_FAILING_EDGE)
				{
					CLEAR_BIT(EXTINT_MCUCR_REG,2);
					SET_BIT(EXTINT_MCUCR_REG,3);
				}
				else if (sensCtrl == EXT_BOTH_EDGE)
				{
					SET_BIT(EXTINT_MCUCR_REG,2);
					CLEAR_BIT(EXTINT_MCUCR_REG,3);
				}
				else if (sensCtrl == EXT_LOW_LEVEL)
				{
					CLEAR_BIT(EXTINT_MCUCR_REG,2);
					CLEAR_BIT(EXTINT_MCUCR_REG,3);
				}
				else
				{
					/*	Do Nothing	*/
				}

		SET_BIT(EXTINT_GICR_REG,INT1_EN_BIT);
		break;

	case EXT_INT2:

		if (sensCtrl == EXT_FAILING_EDGE)
		{
			CLEAR_BIT(EXTINT_MCUCSR_REG,6);
		}
		else if (sensCtrl == EXT_RISING_EDGE)
		{
			SET_BIT(EXTINT_MCUCSR_REG,6);
		}
		else
		{
			/*	Do Nothing	*/
		}
		SET_BIT(EXTINT_GICR_REG,INT2_EN_BIT);
		break;
	}
}

void ExtInt_vidDisableExtInt(extint_id_t intId)
{
	switch (intId)
	{
	case EXT_INT0:
		SET_BIT(EXTINT_GICR_REG,INT0_EN_BIT);
		break;

	case EXT_INT1:
		SET_BIT(EXTINT_GICR_REG,INT1_EN_BIT);
		break;

	case EXT_INT2:
		SET_BIT(EXTINT_GICR_REG,INT2_EN_BIT);
		break;
	}
}
