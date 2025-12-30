/*
 * Random_0_to_6.s
 *
 *  Created on: Dec 26, 2025
 *      Author: saman
 */
.syntax unified
.cpu cortex-m3
.thumb

.section .text
.global random_0_to_6
.type random_0_to_6, %function
.extern Get_random_num
random_0_to_6:
		PUSH {LR}

WHILE:
		BL Get_random_num
		CMP R0,#252
		BHS WHILE
	    MOV  R1, #7        //R1 = 7
	    UDIV R2, R0, R1    //R2 = r / 7   (quotient)
	    MUL  R3, R2, R1    //R3 = (r / 7) * 7
	    SUB  R0, R0, R3    //R0 = r - (r/7)*7
		POP {PC}
