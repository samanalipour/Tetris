/*
 * Check_fill_row.S
 *
 *  Created on: Dec 29, 2025
 *      Author: saman
 */
.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global Check_fill_row
.type   Check_fill_row, %function

.extern Game_field
.extern Game_field_color
.extern ST7789_DrawBlock
.extern Score

Y_CNT       .req R0
X_CNT       .req R1
YY_CNT      .req R2
TMP1        .req R3
TMP2        .req R4
TMP3        .req R5
TMP4        .req R6
FULL        .req R7
TMP5        .req R8
TMP6        .req R9

Check_fill_row:
    PUSH {R4-R9, LR}

    MOV  Y_CNT, #19

ROW_SCAN:
    MOV  FULL, #1
    MOV  X_CNT, #0

CHECK_ROW:
    LDR  TMP1, =Game_field
    MOV  TMP2, #20
    MUL  TMP3, X_CNT, TMP2
    ADD  TMP3, TMP3, Y_CNT
    LDRB TMP3, [TMP1, TMP3]
    CMP  TMP3, #0
    BNE  NEXT_X
    MOV  FULL, #0
    B    ROW_DONE

NEXT_X:
    ADD  X_CNT, #1
    CMP  X_CNT, #10
    BLO  CHECK_ROW

ROW_DONE:
    CMP  FULL, #0
    BEQ  NEXT_Y

    MOV  X_CNT, #0

CLEAR_ROW:
    LDR  TMP1, =Game_field
    MOV  TMP2, #20
    MUL  TMP3, X_CNT, TMP2
    ADD  TMP3, TMP3, Y_CNT
    MOV  TMP4, #0
    STRB TMP4, [TMP1, TMP3]

    LDR  TMP1, =Game_field_color
    LSL  TMP5, TMP3, #1
    STRH TMP4, [TMP1, TMP5]

    MOV  TMP1, #70
    MOV  TMP2, X_CNT
    MOV  TMP3, #10
    MUL  TMP2, TMP2, TMP3
    ADD  TMP1, TMP1, TMP2

    MOV  TMP2, #50
    MOV  TMP3, Y_CNT
    MOV  TMP4, #10
    MUL  TMP3, TMP3, TMP4
    ADD  TMP2, TMP2, TMP3

    MOV  TMP3, #0
    LDR  TMP4, =0x8430
    PUSH {R0-R3}
    MOV  R0, TMP1
    MOV  R1, TMP2
    MOV  R2, TMP3
    MOV  R3, TMP4
    BL   ST7789_DrawBlock
    POP  {R0-R3}

    ADD  X_CNT, #1
    CMP  X_CNT, #10
    BLO  CLEAR_ROW

    MOV  YY_CNT, Y_CNT

SHIFT_ROWS:
    CMP  YY_CNT, #0
    BEQ  AFTER_SHIFT
    MOV  X_CNT, #0

SHIFT_COL:
    MOV  TMP2, #20
    SUB  TMP6, YY_CNT, #1
    MUL  TMP4, X_CNT, TMP2
    ADD  TMP4, TMP4, TMP6

    LDR  TMP1, =Game_field
    LDRB TMP3, [TMP1, TMP4]

    CMP  TMP3, #0
    BEQ  SKIP_CLEAR_SRC

    MOV  TMP5, #70
    MOV  TMP1, X_CNT
    MOV  TMP2, #10
    MUL  TMP1, TMP1, TMP2
    ADD  TMP5, TMP5, TMP1

    MOV  TMP1, #50
    MOV  TMP2, TMP6
    MOV  TMP4, #10
    MUL  TMP2, TMP2, TMP4
    ADD  TMP1, TMP1, TMP2

    MOV  TMP2, #0
    LDR  TMP4, =0x8430
    PUSH {R0-R3}
    MOV  R0, TMP5
    MOV  R1, TMP1
    MOV  R2, TMP2
    MOV  R3, TMP4
    BL   ST7789_DrawBlock
    POP  {R0-R3}

SKIP_CLEAR_SRC:
    MOV  TMP2, #20
    MUL  TMP4, X_CNT, TMP2
    ADD  TMP4, TMP4, YY_CNT

    LDR  TMP1, =Game_field
    STRB TMP3, [TMP1, TMP4]

    LDR  TMP1, =Game_field_color
    MOV  TMP2, #20
    MUL  TMP6, X_CNT, TMP2
    ADD  TMP6, TMP6, YY_CNT
    SUB  TMP6, TMP6, #1
    LSL  TMP6, TMP6, #1
    LDRH TMP2, [TMP1, TMP6]

    LSL  TMP6, TMP4, #1
    STRH TMP2, [TMP1, TMP6]

    CMP  TMP3, #0
    BEQ  NEXT_SHIFT_X

    MOV  TMP5, #70
    MOV  TMP1, X_CNT
    MOV  TMP4, #10
    MUL  TMP1, TMP1, TMP4
    ADD  TMP5, TMP5, TMP1

    MOV  TMP1, #50
    MOV  TMP4, YY_CNT
    MOV  TMP3, #10
    MUL  TMP4, TMP4, TMP3
    ADD  TMP1, TMP1, TMP4

    LDR  TMP4, =0x8430
    PUSH {R0-R3}
    MOV  R0, TMP5
    MOV  R1, TMP1
    MOV  R2, TMP2
    MOV  R3, TMP4
    BL   ST7789_DrawBlock
    POP  {R0-R3}

NEXT_SHIFT_X:
    ADD  X_CNT, #1
    CMP  X_CNT, #10
    BLO  SHIFT_COL

    SUB  YY_CNT, #1
    B    SHIFT_ROWS

AFTER_SHIFT:
    ADD  Y_CNT, #1
    LDR  TMP1, =Score
    LDRH TMP2, [TMP1]
    ADD  TMP2, TMP2, #100
    STRH TMP2, [TMP1]

NEXT_Y:
    SUB  Y_CNT, #1
    CMP  Y_CNT, #0
    BGE  ROW_SCAN

    POP  {R4-R9, PC}
