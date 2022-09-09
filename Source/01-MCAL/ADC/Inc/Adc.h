/*
 * Adc.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_ADC_INC_ADC_H_
#define SOURCE_01_MCAL_ADC_INC_ADC_H_

#include "Adc_Types.h"

void Adc_vidInit(void);
u16 Adc_u16AdcRead(adc_channlId_t channel);

#endif /* SOURCE_01_MCAL_ADC_INC_ADC_H_ */
