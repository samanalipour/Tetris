/*
 * Copy_object.s
 *
 *  Created on: Dec 30, 2025
 *      Author: saman
 */


.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Copy_object
.type   Copy_object, %function

.extern Prev_current_piece
.extern Current_piece

I_CNT   .req R0
J_CNT   .req R1
TMP1    .req R2
TMP2    .req R3
TMP3    .req R4

Copy_object:
    PUSH {R4, LR}
    MOV  I_CNT, #0
ROW_LOOP:
    MOV  J_CNT, #0
COL_LOOP:
    LSL  TMP1, I_CNT, #2
    ADD  TMP1, TMP1, J_CNT
    LDR  TMP2, =Current_piece
    LDRB TMP3, [TMP2, TMP1]
    LDR  TMP2, =Prev_current_piece
    STRB TMP3, [TMP2, TMP1]
    ADD  J_CNT, #1
    CMP  J_CNT, #4
    BLO  COL_LOOP
    ADD  I_CNT, #1
    CMP  I_CNT, #4
    BLO  ROW_LOOP
    POP  {R4, PC}
