/*********************************************************************************************************
**--------------Template Info---------------------------------------------------------------------------------
** Last modified Date:  2025-01-05
** Last Version:        V1.00
** Descriptions:        This template includes all the peripheral libraries covered in the Computer Architecture 
**											course, as well as instructions for SysTick and exception configuration.
** Author:    					Saman Alipour
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "Main.h"

// Button pins: P2.10(INT0), P2.11(INT1), P2.12(INT2)
// LED pins: P2.0, P2.1, P2.2, P2.3, P2.4, P2.5, P2.6, P2.7
// Joystick pins: P1.26(Down), P1.27(Left), P1.28(Right), P1.29(Up)
// ADC channel: 5
// Audio freq: const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
// uint16_t SinTable[45] =                                       
// {
//     410, 467, 523, 576, 627, 673, 714, 749, 778,
//     799, 813, 819, 817, 807, 789, 764, 732, 694, 
//     650, 602, 550, 495, 438, 381, 324, 270, 217,
//     169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
//     20 , 41 , 70 , 105, 146, 193, 243, 297, 353
// };
// Simulator DARMP1.DLL		-pLPC1768
// Debugger  TARMP1.DLL		-pLPC1768
// LandTiger TARMP1.DLL		-pLPC1768 -dLandTiger
#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif
extern uint16_t Score;
int main(){
	SystemInit();

	//DAC
		//DAC_init();
		//DAC_write(500);
	
	//Timer
		init_timer_SRI(0,0xFFFFF,0b011);			//stop reset interrupt
		enable_timer(0);
		//uint32_t timer_value = read_timer(0);
	
	//Delay 
		//init_timer_SRI(3,25000,0b011);			//1ms delay
		//enable_timer(3);
		//delay_ms(50);
	
	//Button
		BUTTON_init();
	
	//LED
		//LED_init();
		//LED_On(0);
	  //LED_Off(0);
		//LED_Out(255);
	
	//Joystick
		joystick_init();
		
	//RIT
		//init_RIT(0xFFF);
		//enable_RIT();
		
	//ADC
		//ADC_init();
		//ADC_start_conversion();
	
	//GLCD
		LCD_Initialization();
		LCD_Clear(Black);
		GUI_Text(96,128,(uint8_t *)"Tetris",White,Black); // 6 -> 48
		GUI_Text(20,160,(uint8_t *)"Press the button to start",White,Black); // 25 -> 200

	//Touch
		//TP_Init();
		//TouchPanel_Calibrate();
		//TP_DrawPoint(display.x,display.y);
		//getDisplayPoint(&display, Read_Ads7846(), &matrix );
  for(int i=0;i<10;i++){
    for(int j=0;j<20;j++){
      Game_field[i][j] = 0;
      Game_field_color[i][j]=0;
    }
  }
	Score = 0;
	while(1){
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
      uint8_t index = (uint8_t)read_timer(0);
			index &= 0x07;
      Spawn_new_piece(index);
      GameStatus = GAME_START;
    }
  }
	}
	
}