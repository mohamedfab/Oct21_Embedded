/*
 * Timer0_Types.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_

typedef enum
{
	CLK_No_PRESCALER,		/*	clk		 */
	CLK_8_Prescaler,		/*	clk/8	 */
	CLK_64_Prescaler,		/*	clk/64	 */
	CLK_256_Prescaler,		/*	clk/256	 */
	CLK_1024_Prescaler		/*	clk/1024 */
}timer0_clk_t;

#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_TYPES_H_ */
