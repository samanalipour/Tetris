/*
 * main.h
 *
 *  Created on: Dec 17, 2025
 *      Author: saman
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f1xx_hal.h"
#include "Global_variables.h"
#include "Peripherals.h"
#include "Printf_redirect.h"
#include "st7789.h"
#include "Tetris.h"

#define SPI_RES_Pin GPIO_PIN_6
#define SPI_RES_GPIO_Port GPIOA
#define SPI_DC_Pin GPIO_PIN_0
#define SPI_DC_GPIO_Port GPIOB
#define SPI_CS_Pin GPIO_PIN_1
#define SPI_CS_GPIO_Port GPIOB
#define SW_Pin GPIO_PIN_9
#define SW_GPIO_Port GPIOB
#endif /* INC_MAIN_H_ */
