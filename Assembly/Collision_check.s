/*
 * Collision_check.s
 *
 *  Created on: Dec 27, 2025
 *      Author: saman
 */

.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Collision_check
.type   Collision_check, %function

.extern row_occupied
.extern Game_field
PIECE 		.req 	R0
TEST_X 		.req 	R1
TEST_Y 		.req 	R2
DRAW_ROW 	.req	R3
I_CNT		.req	R4
J_CNT		.req	R5
TMP1		.req	R6
TMP2		.req	R7
Collision_check:
    PUSH {R4-R7, LR}
	LDR	DRAW_ROW,=0

	LDR	I_CNT,=3
ROW_LOOP:
	PUSH {R0-R3}
	MOV R1,I_CNT
	BL row_occupied
	MOV TMP1,R0
	POP {R0-R3}
	CMP TMP1,#0
	BEQ NEXT_I
	LDR J_CNT,=0
COL_LOOP:
	LSL TMP1,I_CNT,#2
	ADD TMP1,J_CNT
	LDRB TMP1,[PIECE,TMP1]
	CMP TMP1,#1
	BNE NEXT_J
	ADD TMP1,TEST_X,J_CNT
	LDR TMP2,=20
	MUL TMP1,TMP1,TMP2
	SUB TMP2,TEST_Y,DRAW_ROW
	ADD TMP1,TMP2
	LDR TMP2,=Game_field
	LDRB TMP1,[TMP2,TMP1]
	CMP TMP1,#0
	BNE COLLISION
NEXT_J:
	ADD J_CNT,J_CNT,#1
	CMP J_CNT,#4
	BLO COL_LOOP

	ADD DRAW_ROW,#1
NEXT_I:
    SUB  I_CNT, I_CNT, #1
    CMP  I_CNT,#0
    BGE  ROW_LOOP

NO_COLLISION:
    LDR  R0, =1
    POP  {R4-R7, PC}

COLLISION:
    LDR  R0, =0
    POP  {R4-R7, PC}



