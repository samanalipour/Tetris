/*
 * Write_piece_to_game_field.s
 *
 *  Created on: Dec 22, 2025
 *      Author: saman
 */


.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Write_piece_to_game_field
.type   Write_piece_to_game_field, %function

.extern row_occupied
.extern Game_field
.extern Game_field_color
.extern Current_piece_color

PIECE       .req R0
PIECE_X     .req R1
PIECE_Y     .req R2
DRAW_ROW    .req R3
I_CNT       .req R4
J_CNT       .req R5
TMP1        .req R6
TMP2        .req R7
TMP3        .req R8
TMP4        .req R9

Write_piece_to_game_field:
    PUSH {R4-R9, LR}

    MOV  DRAW_ROW, #0
    MOV  I_CNT, #3

ROW_LOOP:
    PUSH {R0-R3}
    MOV  R1, I_CNT
    BL   row_occupied
    MOV  TMP1, R0
    POP  {R0-R3}

    CMP  TMP1, #0
    BEQ  NEXT_I

    MOV  J_CNT, #0

COL_LOOP:
    LSL  TMP1, I_CNT, #2
    ADD  TMP1, TMP1, J_CNT
    LDRB TMP1, [PIECE, TMP1]
    CMP  TMP1, #0
    BEQ  NEXT_J

    ADD  TMP2, PIECE_X, J_CNT
    SUB  TMP3, PIECE_Y, DRAW_ROW

    CMP  TMP2, #0
    BLT  NEXT_J
    CMP  TMP2, #10
    BGE  NEXT_J
    CMP  TMP3, #0
    BLT  NEXT_J
    CMP  TMP3, #20
    BGE  NEXT_J

    MOV  TMP4, #20
    MUL  TMP4, TMP2, TMP4
    ADD  TMP4, TMP4, TMP3

    LDR  TMP1, =Game_field
    MOV  TMP2, #1
    STRB TMP2, [TMP1, TMP4]

    LDR  TMP1, =Current_piece_color
    LDRH TMP2, [TMP1]

    LDR  TMP1, =Game_field_color
    LSL  TMP3, TMP4, #1
    STRH TMP2, [TMP1, TMP3]

NEXT_J:
    ADD  J_CNT, #1
    CMP  J_CNT, #4
    BLO  COL_LOOP

    ADD  DRAW_ROW, #1

NEXT_I:
    SUB  I_CNT, I_CNT, #1
    CMP  I_CNT, #0
    BGE  ROW_LOOP

    POP  {R4-R9, PC}
