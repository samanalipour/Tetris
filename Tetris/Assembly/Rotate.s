/*
 * Rotate.s
 *
 *  Created on: Dec 30, 2025
 *      Author: saman
 */

.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Rotate
.type   Rotate, %function

OBJECT  .req R0
Y_CNT   .req R1
X_CNT   .req R2
TMP1    .req R3
TMP2    .req R4
TMP3    .req R5
TMP4    .req R6
TMP5    .req R7

Rotate:
    PUSH {R4-R7, LR}
    SUB  SP, SP, #16

    MOV  Y_CNT, #0

ROT_Y:
    MOV  X_CNT, #0

ROT_X:
    LSL  TMP1, Y_CNT, #2
    ADD  TMP1, TMP1, X_CNT
    LDRB TMP2, [OBJECT, TMP1]
    MOV  TMP3, #3
    SUB  TMP3, TMP3, Y_CNT
    LSL  TMP4, X_CNT, #2
    ADD  TMP4, TMP4, TMP3
    ADD  TMP5, SP, TMP4
    STRB TMP2, [TMP5]
    ADD  X_CNT, #1
    CMP  X_CNT, #4
    BLO  ROT_X
    ADD  Y_CNT, #1
    CMP  Y_CNT, #4
    BLO  ROT_Y
    MOV  Y_CNT, #0
COPY_Y:
    MOV  X_CNT, #0
COPY_X:
    LSL  TMP1, Y_CNT, #2
    ADD  TMP1, TMP1, X_CNT
    ADD  TMP2, SP, TMP1
    LDRB TMP3, [TMP2]
    STRB TMP3, [OBJECT, TMP1]
    ADD  X_CNT, #1
    CMP  X_CNT, #4
    BLO  COPY_X
    ADD  Y_CNT, #1
    CMP  Y_CNT, #4
    BLO  COPY_Y
    ADD  SP, SP, #16
    POP  {R4-R7, PC}


