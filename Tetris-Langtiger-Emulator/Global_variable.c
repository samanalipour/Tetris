#include "Global_variable.h"
bool ADC_conversion = false;
bool SW_flag = false;
uint8_t Current_piece[4][4];
uint8_t Game_field [10][20];
uint16_t Game_field_color [10][20];
GameState_t GameStatus = GAME_STARTUP;
uint16_t ADC_result[2];