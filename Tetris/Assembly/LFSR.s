/*
 * Random_0_to_6.s
 *
 *  Created on: Dec 23, 2025
 *      Author: saman
 */
.syntax unified
.cpu cortex-m3
.thumb

.section .data
.align 1
.global LFSR_SEED
LFSR_SEED:
    .byte 0xA5        //non-zero default

.section .text
.global Get_random_num
.type Get_random_num, %function

Get_random_num:
    PUSH {LR}

    LDR  R1, =LFSR_SEED
    LDRB R0, [R1]

    ANDS R2, R0, #1
    LSRS R0, R0, #1

    CMP  R2, #0
    BEQ  NO_XOR
    EORS R0, R0, #0x8E

NO_XOR:
    STRB R0, [R1]

    POP {PC}
