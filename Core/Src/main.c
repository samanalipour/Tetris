#include "main.h"
void System_Config(void);

void Game_loop(void);

int main(void)
{
  System_Config();
  while (1)
  {
    Game_loop();
  }
}

void System_Config(void){
  HAL_Init();
  RCC_config();
  Debugger_config();
  LED_config();
  SW_config();
  TIM3_config();
  ADC_config();
  SPI_config();
  printf("Power up...!\n");
  HAL_TIM_Base_Start_IT(&TIM3Handle);
  HAL_ADC_Start_DMA(&ADC1Handle, (uint32_t *)ADC_result, 2);
  ST7789_Init();
  ST7789_WriteString(72,117,(char *)"Tetris",Font_16x26,WHITE,BLACK);
  ST7789_WriteString(32,153,(char *)"Press the button to start",Font_7x10,WHITE,BLACK);
  for(int i=0;i<10;i++){
    for(int j=0;j<20;j++){
      Game_field[i][j] = 0;
      Game_field_color[i][j]=0;
    }
  }
}

void Game_loop(void){
  if(ADC_conversion){
    ADC_conversion = false;
    Check_joystick();
  }

  if(SW_flag){
    SW_flag = false;
    if(GameStatus == GAME_PAUSE)GameStatus = GAME_START;
    else if(GameStatus == GAME_START)GameStatus = GAME_PAUSE;
    else if(GameStatus == GAME_STARTUP){
      Map();
      uint8_t seed = (uint8_t)__HAL_TIM_GET_COUNTER(&TIM3Handle);
      if (seed == 0) seed = 0xA5;
      LFSR_SEED = seed;
      uint8_t index = Get_random_num() & 0x07;
      Spawn_new_piece(index);
      GameStatus = GAME_START;
    }
    Start_pause();
  }
}
