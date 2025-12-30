/*
 * Global_variables.h
 *
 *  Created on: Dec 26, 2025
 *      Author: saman
 */

#ifndef INC_GLOBAL_VARIABLES_H_
#define INC_GLOBAL_VARIABLES_H_
#include "main.h"
typedef enum
{
    GAME_PAUSE = 0,
    GAME_START = 1,
    GAME_STARTUP = 2,
    GAME_OVER = 3
} GameState_t;

extern bool ADC_conversion ;
extern bool SW_flag;
extern uint8_t Current_piece[4][4];
extern uint8_t Game_field [10][20];
extern uint16_t Game_field_color [10][20];
extern GameState_t GameStatus;
extern uint16_t ADC_result[2];
extern ADC_HandleTypeDef ADC1Handle;
extern DMA_HandleTypeDef ADC_DMA;
extern TIM_HandleTypeDef TIM3Handle;
extern SPI_HandleTypeDef SPIHandle;
uint8_t Get_random_num(void);
extern volatile uint8_t LFSR_SEED;

#endif /* INC_GLOBAL_VARIABLES_H_ */
