/*
 * Tetris.c
 *
 *  Created on: Dec 22, 2025
 *      Author: saman
 */

#include "Tetris.h"
uint8_t Prev_current_piece[4][4];
int piece_x = 3;
int piece_y = 0;
int prev_piece_x;
int prev_piece_y;
uint16_t Score = 0;
uint16_t Top = 0;
char score_str[16];
char top_str[16];
uint16_t Current_piece_color;
const uint16_t PIECE_COLORS[7] = {
    CYAN,     // I
    YELLOW,   // O
    MAGENTA,  // T
    GREEN,    // S
    RED,      // Z
    BLUE,     // J
    ORANGE    // L
};

const uint8_t TETROMINO[7][4][4] = {

    // I
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    // O
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    },

    // T
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    },

    // S
    {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    },

    // Z
    {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    },

    // J
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    },

    // L
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

void Draw_score(uint16_t score, uint16_t top)
{
  snprintf(score_str, sizeof(score_str), "Score %05d", score);
  snprintf(top_str,   sizeof(top_str),   "Top %05d",   top);
  ST7789_WriteString(20, 16, score_str, Font_7x10, WHITE, BLACK);
  ST7789_WriteString(157,16, top_str,   Font_7x10, WHITE, BLACK);
}

//uint8_t random_0_to_6(void)
//{
//  uint8_t r;
//
//  do {
//    r = Get_random_num();
//  } while (r >= 252);
//
//  return r % 7;
//}

//void Check_fill_row(void)
//{
//  // scan from bottom to top
//  for (int y = 19; y >= 0; y--)
//  {
//    uint8_t full = 1;
//
//    for (uint8_t x = 0; x < 10; x++)
//    {
//      if (Game_field[x][y] == 0)
//      {
//        full = 0;
//        break;
//      }
//    }
//
//    if (full)
//    {
//      for (uint8_t x = 0; x < 10; x++){
//        Game_field[x][y] = 0;
//        Game_field_color[x][y]=0;
//        ST7789_DrawBlock(70+x*10, 50+y*10, BLACK, GRAY);
//      }
//
//      for (int yy = y; yy > 0; yy--)
//      {
//        for (uint8_t x = 0; x < 10; x++){
//          if(Game_field[x][yy - 1])ST7789_DrawBlock(70+x*10, 50+(yy-1)*10, BLACK, GRAY);
//          Game_field[x][yy] = Game_field[x][yy - 1];
//          Game_field_color[x][yy] = Game_field_color[x][yy - 1];
//          if(Game_field[x][yy])ST7789_DrawBlock(70+x*10, 50+yy*10, Game_field_color[x][yy], GRAY);
//        }
//      }
//      y++;
//      Score+=100;
//    }
//  }
//}

void Map(void){
  ST7789_Fill_Color(BLACK);
  Draw_score(Score, Top);
  ST7789_DrawRectangle(69,49,171,251,WHITE);
  for(int i=0;i<20;i++){
    for(int j=0;j<10;j++){
      ST7789_DrawBlock(70+j*10, 50+i*10, BLACK, GRAY);
    }
  }
}

//void Copy_object(void){
//  for(int i=0;i<4;i++){
//    for(int j=0;j<4;j++){
//      Prev_current_piece[i][j] = Current_piece[i][j];
//    }
//  }
//}

//uint8_t row_occupied(uint8_t piece[4][4], uint8_t r){
//  for (uint8_t c = 0; c < 4; c++)
//    if (piece[r][c])
//      return 1;
//  return 0;
//}

//void Write_piece_to_game_field(uint8_t piece[4][4],int piece_x,int piece_y){
//  int draw_row = 0;
//  // scan piece rows from bottom (3) to top (0)
//  for (int i = 3; i >= 0; i--)
//  {
//    if (!row_occupied(piece, i))
//      continue;   // skip empty rows
//    for (uint8_t j = 0; j < 4; j++)
//    {
//      if (piece[i][j])
//      {
//        int gx = piece_x + j;
//        int gy = piece_y - draw_row;
//
//        if (gx >= 0 && gx < 10 && gy >= 0 && gy < 20)
//        {
//          Game_field[gx][gy] = 1;
//          Game_field_color[gx][gy] = Current_piece_color;
//        }
//      }
//    }
//
//    draw_row++;   // only advance when row is drawn
//  }
//}

//bool Collision_check(uint8_t piece[4][4], int test_x, int test_y){
//  int draw_row = 0;
//
//  // scan from bottom (row 3) to top (row 0)
//  for (int i = 3; i >= 0; i--)
//  {
//    if (!row_occupied(piece, i))
//      continue;
//
//    for (uint8_t j = 0; j < 4; j++)
//    {
//      if (piece[i][j])
//      {
//        int gx = test_x + j;
//        int gy = test_y - draw_row;
//        // COLLISION WITH LOCKED BLOCKS
//        if (Game_field[gx][gy])
//          return 0;
//      }
//    }
//
//    draw_row++;
//  }
//
//  return 1;
//}

//bool Check_wall(uint8_t piece[4][4], int test_x){
//  for (uint8_t i = 0; i < 4; i++)
//  {
//    for (uint8_t j = 0; j < 4; j++)
//    {
//      if (piece[i][j])
//      {
//        int gx = test_x + j;
//
//        // LEFT / RIGHT WALL CHECK
//        if (gx < 0 || gx >= 10)
//          return false;
//      }
//    }
//  }
//
//  return true;   // no wall collision
//}

//void Rotate(uint8_t object[4][4]){
//  uint8_t tmp[4][4];
//  for (uint8_t y = 0; y < 4; y++)
//  {
//    for (uint8_t x = 0; x < 4; x++)
//    {
//      tmp[x][3 - y] = object[y][x];
//    }
//  }
//  memcpy(object, tmp, sizeof(tmp));
//}

void Check_joystick(void){
  if(GameStatus == GAME_START){
    bool lock = Collision_check(Current_piece,piece_x,piece_y);
    if(piece_y<20 && lock){
      Copy_object();
      if(ADC_result[0]<500){       //UP
        printf("UP\n");
        prev_piece_x = piece_x;
        Rotate(Current_piece);
      }else if(ADC_result[1]<500){ //RIGHT
        printf("RIGHT %d\n",piece_x);
        if (Check_wall(Current_piece, piece_x + 1)){
          prev_piece_x = piece_x;
          piece_x++;

        }else{
          prev_piece_x = piece_x;
        }
      }else if(ADC_result[1]>3500){ //LEFT
        printf("LEFT %d\n",piece_x);
        if (Check_wall(Current_piece, piece_x - 1)){
          prev_piece_x = piece_x;
          piece_x--;

        }else{
          prev_piece_x = piece_x;
        }
      }else{
        prev_piece_x = piece_x;
      }
      if(ADC_result[0]>3500){
        TIM3_UpdatePeriod(125);
      }else{
        TIM3_UpdatePeriod(1000);
      }
      Draw_active_piece();
      prev_piece_y = piece_y;
      piece_y += 1;
    }else{
      Write_piece_to_game_field(Current_piece,piece_x,piece_y-1);
      Score+=10;
      Check_fill_row();
      uint8_t index = random_0_to_6();
      Draw_score(Score, Top);
      Spawn_new_piece(index);

    }
  }
}

void Draw_current_piece(void){
  int draw_row = 0;  // how many occupied rows we already drew

  // scan from bottom (row 3) to top (row 0)
  for (int i = 3; i >= 0; i--)
  {
    if (!row_occupied(Current_piece, i))
      continue;   // skip empty rows

    for (uint8_t j = 0; j < 4; j++)
    {
      if (Current_piece[i][j])
      {
        ST7789_DrawBlock(
            70 + j * 10 + piece_x * 10,
            50 + (piece_y - draw_row) * 10,
            Current_piece_color,
            GRAY
        );
      }
    }

    draw_row++;  // only move up AFTER drawing a filled row
  }
}

void Erase_prev_piece(void){
  int draw_row = 0;

  for (int i = 3; i >= 0; i--)
  {
    if (!row_occupied(Prev_current_piece, i))
      continue;

    for (uint8_t j = 0; j < 4; j++)
    {
      if (Prev_current_piece[i][j])
      {
        ST7789_DrawBlock(70 + j * 10 + prev_piece_x * 10, 50 + (prev_piece_y - draw_row) * 10, BLACK, GRAY);
      }
    }

    draw_row++;
  }
}

void Draw_active_piece(void){
  Erase_prev_piece();
  Draw_current_piece();
}

void Start_pause(void){
  if(GameStatus == GAME_STARTUP){
  }else if(GameStatus == GAME_PAUSE){
    printf("Pause...\n");
  }else if(GameStatus == GAME_START){
    printf("Resume...\n");
  }
}

void Spawn_new_piece(uint8_t id){
  piece_x = 3;
  piece_y = 1;
  prev_piece_x = piece_x;
  prev_piece_y = piece_y;
  for (uint8_t i = 0; i < 4; i++)
  {
    for (uint8_t j = 0; j < 4; j++)
    {
      Current_piece[i][j] = TETROMINO[id][i][j];
    }
  }
  Current_piece_color = PIECE_COLORS[id];

  if (!Collision_check(Current_piece, piece_x, piece_y))
  {
    GameStatus = GAME_STARTUP;
    ST7789_WriteString(40,127,(char *)"GAME OVER",Font_16x26,WHITE,BLACK);
    HAL_Delay(2000);
    ST7789_Fill_Color(BLACK);
    ST7789_WriteString(72,117,(char *)"Tetris",Font_16x26,WHITE,BLACK);
    ST7789_WriteString(32,153,(char *)"Press the button to start",Font_7x10,WHITE,BLACK);
    for(int i=0;i<10;i++){
      for(int j=0;j<20;j++){
        Game_field[i][j] = 0;
        Game_field_color[i][j]=0;
      }
    }
    printf("GAME OVER\n");
  }
}

