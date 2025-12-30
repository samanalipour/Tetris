/*
 * stm32f1xx_it.c
 *
 *  Created on: Dec 17, 2025
 *      Author: saman
 */

#include "stm32f1xx_it.h"

void SysTick_Handler(void){
  HAL_IncTick();
}


void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TIM3Handle);
}

void DMA1_Channel1_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&ADC_DMA);
}

void ADC1_2_IRQHandler(void)
{
  HAL_ADC_IRQHandler(&ADC1Handle);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  ADC_conversion = true;
//   printf("ADC0 %d\t\t ADC1 %d\n",ADC_result[0],ADC_result[1]);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//  printf("ADC = \r\n");
//  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == SW_Pin){
    SW_flag = true;
  }
}

void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(SW_Pin);
}
