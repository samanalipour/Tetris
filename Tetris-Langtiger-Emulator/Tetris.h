#ifndef __TETRIS_H 
#define __TETRIS_H
#include "Main.h"
void Check_fill_row(void);
void Map(void);
void Copy_object(void);
uint8_t row_occupied(uint8_t piece[4][4], uint8_t r);
void Write_piece_to_game_field(uint8_t piece[4][4],int piece_x,int piece_y);
bool Collision_check(uint8_t piece[4][4], int test_x, int test_y);
bool Check_wall(uint8_t piece[4][4], int test_x);
void Rotate(uint8_t object[4][4]);
void Check_joystick(void);
void Draw_current_piece(void);
void Erase_prev_piece(void);
void Start_pause(void);
void Draw_active_piece(void);
void Spawn_new_piece(uint8_t id);
#endif 