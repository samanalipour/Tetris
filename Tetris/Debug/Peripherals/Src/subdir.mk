################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripherals/Src/Peripherals.c \
../Peripherals/Src/Printf_redirect.c 

OBJS += \
./Peripherals/Src/Peripherals.o \
./Peripherals/Src/Printf_redirect.o 

C_DEPS += \
./Peripherals/Src/Peripherals.d \
./Peripherals/Src/Printf_redirect.d 


# Each subdirectory must supply rules for building sources it contributes
Peripherals/Src/%.o Peripherals/Src/%.su Peripherals/Src/%.cyclo: ../Peripherals/Src/%.c Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I"/home/saman/Desktop/Tetris/CMSIS/Device" -I"/home/saman/Desktop/Tetris/CMSIS/Include" -I"/home/saman/Desktop/Tetris/HAL/Inc" -I"/home/saman/Desktop/Tetris/HAL" -I"/home/saman/Desktop/Tetris/HAL/Inc/Legacy" -I"/home/saman/Desktop/Tetris/Peripherals/Inc" -I"/home/saman/Desktop/Tetris/Core/Inc" -I"/home/saman/Desktop/Tetris/Driver/Inc" -I"/home/saman/Desktop/Tetris/Tetris/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Peripherals-2f-Src

clean-Peripherals-2f-Src:
	-$(RM) ./Peripherals/Src/Peripherals.cyclo ./Peripherals/Src/Peripherals.d ./Peripherals/Src/Peripherals.o ./Peripherals/Src/Peripherals.su ./Peripherals/Src/Printf_redirect.cyclo ./Peripherals/Src/Printf_redirect.d ./Peripherals/Src/Printf_redirect.o ./Peripherals/Src/Printf_redirect.su

.PHONY: clean-Peripherals-2f-Src

