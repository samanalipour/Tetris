/*
 * row_occupied.s
 *
 *  Created on: Dec 29, 2025
 *      Author: saman
 */

.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global row_occupied
.type   row_occupied, %function

PIECE       .req    R0
ROW         .req    R1
C_CNT       .req    R2
TMP         .req    R3

row_occupied:
    PUSH    {LR}

    LDR     C_CNT, =0

COL_LOOP:
    LSL     TMP, ROW, #2
    ADD     TMP, C_CNT
    LDRB    TMP, [PIECE, TMP]
    CMP     TMP, #0
    BNE     ROW_OCCUPIED
    ADD     C_CNT, #1
    CMP     C_CNT, #4
    BLO     COL_LOOP
NO_OCCUPY:
    LDR     R0, =0
    POP     {PC}
ROW_OCCUPIED:
    LDR     R0, =1
    POP     {PC}
