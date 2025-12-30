/*
 * stm32f1xx_it.h
 *
 *  Created on: Dec 17, 2025
 *      Author: saman
 */

#ifndef INC_STM32F1XX_IT_H_
#define INC_STM32F1XX_IT_H_

#include "main.h"
void SysTick_Handler(void);
void TIM3_IRQHandler(void);
void DMA1_Channel1_IRQHandler(void);
void ADC1_2_IRQHandler(void);
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void EXTI9_5_IRQHandler(void);
#endif /* INC_STM32F1XX_IT_H_ */
