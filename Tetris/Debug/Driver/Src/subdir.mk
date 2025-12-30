################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/fonts.c \
../Driver/Src/st7789.c 

OBJS += \
./Driver/Src/fonts.o \
./Driver/Src/st7789.o 

C_DEPS += \
./Driver/Src/fonts.d \
./Driver/Src/st7789.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"/home/saman/Desktop/Tetris/CMSIS/Device" -I"/home/saman/Desktop/Tetris/CMSIS/Include" -I"/home/saman/Desktop/Tetris/HAL/Inc" -I"/home/saman/Desktop/Tetris/HAL" -I"/home/saman/Desktop/Tetris/HAL/Inc/Legacy" -I"/home/saman/Desktop/Tetris/Peripherals/Inc" -I"/home/saman/Desktop/Tetris/Core/Inc" -I"/home/saman/Desktop/Tetris/Driver/Inc" -I"/home/saman/Desktop/Tetris/Tetris/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/fonts.cyclo ./Driver/Src/fonts.d ./Driver/Src/fonts.o ./Driver/Src/fonts.su ./Driver/Src/st7789.cyclo ./Driver/Src/st7789.d ./Driver/Src/st7789.o ./Driver/Src/st7789.su

.PHONY: clean-Driver-2f-Src

