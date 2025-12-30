/*
 * Global_variables.c
 *
 *  Created on: Dec 26, 2025
 *      Author: saman
 */

#include "Global_variables.h"

bool ADC_conversion = false;
bool SW_flag = false;
uint8_t Current_piece[4][4];
uint8_t Game_field [10][20];
uint16_t Game_field_color [10][20];
GameState_t GameStatus = GAME_STARTUP;
uint16_t ADC_result[2];
ADC_HandleTypeDef ADC1Handle;
DMA_HandleTypeDef ADC_DMA;
TIM_HandleTypeDef TIM3Handle;
SPI_HandleTypeDef SPIHandle;
