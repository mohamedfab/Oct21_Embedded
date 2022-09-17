/*
 * Timer0.h
 *
 *  Created on: Sep 14, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_
#define SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_

#include "Std_Types.h"
#include "Timer0_Types.h"

void Timer0_vidInit(void);
void Timer0_vidSetPreload(u8 preload);
void Timer0_vidTimerStart(timer0_clk_t clk);
void Timer0_vidTimerStop(void);

void Timer0_vidEnableOVInterrupt(void);
void Timer0_vidDisableOVInterrupt(void);

void Timer0_vidEnableCTCInterrupt(void);
void Timer0_vidDisableCTCInterrupt(void);




#endif /* SOURCE_01_MCAL_TIMER0_INC_TIMER0_H_ */
