################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Src/stm32f1xx_hal.c \
../HAL/Src/stm32f1xx_hal_adc.c \
../HAL/Src/stm32f1xx_hal_adc_ex.c \
../HAL/Src/stm32f1xx_hal_cortex.c \
../HAL/Src/stm32f1xx_hal_dma.c \
../HAL/Src/stm32f1xx_hal_flash.c \
../HAL/Src/stm32f1xx_hal_flash_ex.c \
../HAL/Src/stm32f1xx_hal_gpio.c \
../HAL/Src/stm32f1xx_hal_gpio_ex.c \
../HAL/Src/stm32f1xx_hal_rcc.c \
../HAL/Src/stm32f1xx_hal_rcc_ex.c \
../HAL/Src/stm32f1xx_hal_spi.c \
../HAL/Src/stm32f1xx_hal_tim.c \
../HAL/Src/stm32f1xx_hal_tim_ex.c 

OBJS += \
./HAL/Src/stm32f1xx_hal.o \
./HAL/Src/stm32f1xx_hal_adc.o \
./HAL/Src/stm32f1xx_hal_adc_ex.o \
./HAL/Src/stm32f1xx_hal_cortex.o \
./HAL/Src/stm32f1xx_hal_dma.o \
./HAL/Src/stm32f1xx_hal_flash.o \
./HAL/Src/stm32f1xx_hal_flash_ex.o \
./HAL/Src/stm32f1xx_hal_gpio.o \
./HAL/Src/stm32f1xx_hal_gpio_ex.o \
./HAL/Src/stm32f1xx_hal_rcc.o \
./HAL/Src/stm32f1xx_hal_rcc_ex.o \
./HAL/Src/stm32f1xx_hal_spi.o \
./HAL/Src/stm32f1xx_hal_tim.o \
./HAL/Src/stm32f1xx_hal_tim_ex.o 

C_DEPS += \
./HAL/Src/stm32f1xx_hal.d \
./HAL/Src/stm32f1xx_hal_adc.d \
./HAL/Src/stm32f1xx_hal_adc_ex.d \
./HAL/Src/stm32f1xx_hal_cortex.d \
./HAL/Src/stm32f1xx_hal_dma.d \
./HAL/Src/stm32f1xx_hal_flash.d \
./HAL/Src/stm32f1xx_hal_flash_ex.d \
./HAL/Src/stm32f1xx_hal_gpio.d \
./HAL/Src/stm32f1xx_hal_gpio_ex.d \
./HAL/Src/stm32f1xx_hal_rcc.d \
./HAL/Src/stm32f1xx_hal_rcc_ex.d \
./HAL/Src/stm32f1xx_hal_spi.d \
./HAL/Src/stm32f1xx_hal_tim.d \
./HAL/Src/stm32f1xx_hal_tim_ex.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Src/%.o HAL/Src/%.su HAL/Src/%.cyclo: ../HAL/Src/%.c HAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"/home/saman/Desktop/Tetris/CMSIS/Device" -I"/home/saman/Desktop/Tetris/CMSIS/Include" -I"/home/saman/Desktop/Tetris/HAL/Inc" -I"/home/saman/Desktop/Tetris/HAL" -I"/home/saman/Desktop/Tetris/HAL/Inc/Legacy" -I"/home/saman/Desktop/Tetris/Peripherals/Inc" -I"/home/saman/Desktop/Tetris/Core/Inc" -I"/home/saman/Desktop/Tetris/Driver/Inc" -I"/home/saman/Desktop/Tetris/Tetris/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Src

clean-HAL-2f-Src:
	-$(RM) ./HAL/Src/stm32f1xx_hal.cyclo ./HAL/Src/stm32f1xx_hal.d ./HAL/Src/stm32f1xx_hal.o ./HAL/Src/stm32f1xx_hal.su ./HAL/Src/stm32f1xx_hal_adc.cyclo ./HAL/Src/stm32f1xx_hal_adc.d ./HAL/Src/stm32f1xx_hal_adc.o ./HAL/Src/stm32f1xx_hal_adc.su ./HAL/Src/stm32f1xx_hal_adc_ex.cyclo ./HAL/Src/stm32f1xx_hal_adc_ex.d ./HAL/Src/stm32f1xx_hal_adc_ex.o ./HAL/Src/stm32f1xx_hal_adc_ex.su ./HAL/Src/stm32f1xx_hal_cortex.cyclo ./HAL/Src/stm32f1xx_hal_cortex.d ./HAL/Src/stm32f1xx_hal_cortex.o ./HAL/Src/stm32f1xx_hal_cortex.su ./HAL/Src/stm32f1xx_hal_dma.cyclo ./HAL/Src/stm32f1xx_hal_dma.d ./HAL/Src/stm32f1xx_hal_dma.o ./HAL/Src/stm32f1xx_hal_dma.su ./HAL/Src/stm32f1xx_hal_flash.cyclo ./HAL/Src/stm32f1xx_hal_flash.d ./HAL/Src/stm32f1xx_hal_flash.o ./HAL/Src/stm32f1xx_hal_flash.su ./HAL/Src/stm32f1xx_hal_flash_ex.cyclo ./HAL/Src/stm32f1xx_hal_flash_ex.d ./HAL/Src/stm32f1xx_hal_flash_ex.o ./HAL/Src/stm32f1xx_hal_flash_ex.su ./HAL/Src/stm32f1xx_hal_gpio.cyclo ./HAL/Src/stm32f1xx_hal_gpio.d ./HAL/Src/stm32f1xx_hal_gpio.o ./HAL/Src/stm32f1xx_hal_gpio.su ./HAL/Src/stm32f1xx_hal_gpio_ex.cyclo ./HAL/Src/stm32f1xx_hal_gpio_ex.d ./HAL/Src/stm32f1xx_hal_gpio_ex.o ./HAL/Src/stm32f1xx_hal_gpio_ex.su ./HAL/Src/stm32f1xx_hal_rcc.cyclo ./HAL/Src/stm32f1xx_hal_rcc.d ./HAL/Src/stm32f1xx_hal_rcc.o ./HAL/Src/stm32f1xx_hal_rcc.su ./HAL/Src/stm32f1xx_hal_rcc_ex.cyclo ./HAL/Src/stm32f1xx_hal_rcc_ex.d ./HAL/Src/stm32f1xx_hal_rcc_ex.o ./HAL/Src/stm32f1xx_hal_rcc_ex.su ./HAL/Src/stm32f1xx_hal_spi.cyclo ./HAL/Src/stm32f1xx_hal_spi.d ./HAL/Src/stm32f1xx_hal_spi.o ./HAL/Src/stm32f1xx_hal_spi.su ./HAL/Src/stm32f1xx_hal_tim.cyclo ./HAL/Src/stm32f1xx_hal_tim.d ./HAL/Src/stm32f1xx_hal_tim.o ./HAL/Src/stm32f1xx_hal_tim.su ./HAL/Src/stm32f1xx_hal_tim_ex.cyclo ./HAL/Src/stm32f1xx_hal_tim_ex.d ./HAL/Src/stm32f1xx_hal_tim_ex.o ./HAL/Src/stm32f1xx_hal_tim_ex.su

.PHONY: clean-HAL-2f-Src

