/*
 * Peripherals.h
 *
 *  Created on: Dec 17, 2025
 *      Author: saman
 */

#ifndef INC_PERIPHERALS_H_
#define INC_PERIPHERALS_H_

#include "main.h"

bool RCC_config(void);
void LED_config(void);
void SW_config(void);
void Debugger_config(void);
bool TIM3_config(void);
bool ADC_config(void);
bool SPI_config(void);
void TIM3_UpdatePeriod(uint32_t period);

#endif /* INC_PERIPHERALS_H_ */
