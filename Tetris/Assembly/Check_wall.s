/*
 * Check_wall.s
 *
 *  Created on: Dec 27, 2025
 *      Author: saman
 */

.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Check_wall
.type   Check_wall, %function
PIECE 		.req 	R0
TEST_X		.req    R1
I_CNT		.req	R2
J_CNT		.req	R3
TMP			.req	R4
Check_wall:
    PUSH {R4, LR}
	LDR	I_CNT,=0

ROW_LOOP:

	LDR	J_CNT,=0
COL_LOOP:
	LSL TMP,I_CNT,#2
	ADD TMP,J_CNT
	LDRB TMP,[PIECE,TMP]
	CMP TMP,#1
	BNE NEXT_COL
	ADD TMP,J_CNT,TEST_X
	CMP TMP,#0
	BLT WALL_HIT
	CMP TMP,#10
	BGE WALL_HIT
NEXT_COL:
	ADD J_CNT,#1
	CMP J_CNT,#4
	BLO COL_LOOP
NEXT_ROW:
	ADD I_CNT,#1
	CMP I_CNT,#4
	BLO ROW_LOOP

NO_COLLISION:
    LDR  R0, =1
    POP  {R4, PC}

WALL_HIT:
    LDR  R0, =0
    POP  {R4, PC}



