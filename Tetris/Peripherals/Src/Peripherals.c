/*
 * Peripherals.c
 *
 *  Created on: Dec 17, 2025
 *      Author: saman
 */

#include "Peripherals.h"

/*
 * @brief Clock configuration
 */

bool RCC_config(void){

  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  /*
   * Using HSE
   * Using PLL * 4
   */
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL4;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK){
    return HAL_ERROR;
  }

  /*
   * Using PLL as source of clock
   * APB1 and APB2 divider equal to 1
   */
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK){
    return HAL_ERROR;
  }
  /*
   * ADC prescaler equal to 4
   */
  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit = {0};
  RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  RCC_PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit) != HAL_OK)
  {
    return HAL_ERROR;
  }
   return HAL_OK;
}

/*
 * @brief PC13 LED configuration
 */
void LED_config(void){
  __HAL_RCC_GPIOC_CLK_ENABLE();
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, SET);
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/*
 * @brief Joystick switch configuration
 */
void SW_config(void){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW_GPIO_Port, &GPIO_InitStruct);
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

/*
 * @brief Debugger configuration
 */
void Debugger_config(void){
  /* Enable clocks for AFIO and PWR registers */
  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  /* Disable JTAG, keep SWD active (frees JTAG pins) */
  __HAL_AFIO_REMAP_SWJ_NOJTAG();
}

/*
 * @brief ADC configuration
 */
bool ADC_config(void){
  __HAL_RCC_DMA1_CLK_ENABLE();
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_ADC1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  ADC_DMA.Instance = DMA1_Channel1;
  ADC_DMA.Init.Direction = DMA_PERIPH_TO_MEMORY;
  ADC_DMA.Init.PeriphInc = DMA_PINC_DISABLE;
  ADC_DMA.Init.MemInc = DMA_MINC_ENABLE;
  ADC_DMA.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  ADC_DMA.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  ADC_DMA.Init.Mode = DMA_CIRCULAR;
  ADC_DMA.Init.Priority = DMA_PRIORITY_LOW;
  if (HAL_DMA_Init(&ADC_DMA) != HAL_OK)
  {
    return HAL_ERROR;
  }
  __HAL_LINKDMA(&ADC1Handle,DMA_Handle,ADC_DMA);
  HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(ADC1_2_IRQn);
  ADC_ChannelConfTypeDef ADCConfig = {0};
  ADC1Handle.Instance = ADC1;
  ADC1Handle.Init.ScanConvMode = ADC_SCAN_ENABLE;
  ADC1Handle.Init.ContinuousConvMode = DISABLE;
  ADC1Handle.Init.DiscontinuousConvMode = DISABLE;
  ADC1Handle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
  ADC1Handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  ADC1Handle.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&ADC1Handle) != HAL_OK)
  {
    return HAL_ERROR;
  }
  ADCConfig.Channel = ADC_CHANNEL_0;
  ADCConfig.Rank = ADC_REGULAR_RANK_1;
  ADCConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&ADC1Handle, &ADCConfig) != HAL_OK)
  {
    return HAL_ERROR;
  }
  ADCConfig.Channel = ADC_CHANNEL_1;
  ADCConfig.Rank = ADC_REGULAR_RANK_2;
  if (HAL_ADC_ConfigChannel(&ADC1Handle, &ADCConfig) != HAL_OK)
  {
    return HAL_ERROR;
  }
  return HAL_OK;
}

/*
 * @brief Timer3 configuration
 */
bool TIM3_config(void){
  __HAL_RCC_TIM3_CLK_ENABLE();
  HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM3Handle.Instance = TIM3;
  TIM3Handle.Init.Prescaler = 32000;
  TIM3Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  TIM3Handle.Init.Period = 1000;
  TIM3Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  TIM3Handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&TIM3Handle) != HAL_OK)
  {
    return HAL_ERROR;
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&TIM3Handle, &sClockSourceConfig) != HAL_OK)
  {
    return HAL_ERROR;
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&TIM3Handle, &sMasterConfig) != HAL_OK)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

/*
 * @brief SPI configuration
 */
bool SPI_config(void){
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_SPI1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI_RES_GPIO_Port, SPI_RES_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SPI_DC_Pin|SPI_CS_Pin, GPIO_PIN_RESET);
  /*Configure GPIO pin : SPI_RES_Pin */
  GPIO_InitStruct.Pin = SPI_RES_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI_RES_GPIO_Port, &GPIO_InitStruct);
  /*Configure GPIO pins : SPI_DC_Pin SPI_CS_Pin */
  GPIO_InitStruct.Pin = SPI_DC_Pin|SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  SPIHandle.Instance = SPI1;
  SPIHandle.Init.Mode = SPI_MODE_MASTER;
  SPIHandle.Init.Direction = SPI_DIRECTION_1LINE;
  SPIHandle.Init.DataSize = SPI_DATASIZE_8BIT;
  SPIHandle.Init.CLKPolarity = SPI_POLARITY_HIGH;
  SPIHandle.Init.CLKPhase = SPI_PHASE_2EDGE;
  SPIHandle.Init.NSS = SPI_NSS_SOFT;
  SPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  SPIHandle.Init.FirstBit = SPI_FIRSTBIT_MSB;
  SPIHandle.Init.TIMode = SPI_TIMODE_DISABLE;
  SPIHandle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  SPIHandle.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&SPIHandle) != HAL_OK)
  {
    return HAL_ERROR;
  }
  return HAL_OK;
}

/*
 * @brief Timer3 period change
 */
void TIM3_UpdatePeriod(uint32_t period){
    __HAL_TIM_DISABLE(&TIM3Handle);

    __HAL_TIM_SET_AUTORELOAD(&TIM3Handle, period);

    __HAL_TIM_SET_COUNTER(&TIM3Handle, 0);

    __HAL_TIM_ENABLE(&TIM3Handle);
}
