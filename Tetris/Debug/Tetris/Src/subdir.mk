################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tetris/Src/Tetris.c 

OBJS += \
./Tetris/Src/Tetris.o 

C_DEPS += \
./Tetris/Src/Tetris.d 


# Each subdirectory must supply rules for building sources it contributes
Tetris/Src/%.o Tetris/Src/%.su Tetris/Src/%.cyclo: ../Tetris/Src/%.c Tetris/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"/home/saman/Desktop/Tetris/CMSIS/Device" -I"/home/saman/Desktop/Tetris/CMSIS/Include" -I"/home/saman/Desktop/Tetris/HAL/Inc" -I"/home/saman/Desktop/Tetris/HAL" -I"/home/saman/Desktop/Tetris/HAL/Inc/Legacy" -I"/home/saman/Desktop/Tetris/Peripherals/Inc" -I"/home/saman/Desktop/Tetris/Core/Inc" -I"/home/saman/Desktop/Tetris/Driver/Inc" -I"/home/saman/Desktop/Tetris/Tetris/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Tetris-2f-Src

clean-Tetris-2f-Src:
	-$(RM) ./Tetris/Src/Tetris.cyclo ./Tetris/Src/Tetris.d ./Tetris/Src/Tetris.o ./Tetris/Src/Tetris.su

.PHONY: clean-Tetris-2f-Src

