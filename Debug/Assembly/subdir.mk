################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Assembly/Check_fill_row.s \
../Assembly/Check_wall.s \
../Assembly/Collision_check.s \
../Assembly/Copy_object.s \
../Assembly/LFSR.s \
../Assembly/Random_0_to_6.s \
../Assembly/Rotate.s \
../Assembly/Write_piece_to_game_field.s \
../Assembly/row_occupied.s 

OBJS += \
./Assembly/Check_fill_row.o \
./Assembly/Check_wall.o \
./Assembly/Collision_check.o \
./Assembly/Copy_object.o \
./Assembly/LFSR.o \
./Assembly/Random_0_to_6.o \
./Assembly/Rotate.o \
./Assembly/Write_piece_to_game_field.o \
./Assembly/row_occupied.o 

S_DEPS += \
./Assembly/Check_fill_row.d \
./Assembly/Check_wall.d \
./Assembly/Collision_check.d \
./Assembly/Copy_object.d \
./Assembly/LFSR.d \
./Assembly/Random_0_to_6.d \
./Assembly/Rotate.d \
./Assembly/Write_piece_to_game_field.d \
./Assembly/row_occupied.d 


# Each subdirectory must supply rules for building sources it contributes
Assembly/%.o: ../Assembly/%.s Assembly/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Assembly

clean-Assembly:
	-$(RM) ./Assembly/Check_fill_row.d ./Assembly/Check_fill_row.o ./Assembly/Check_wall.d ./Assembly/Check_wall.o ./Assembly/Collision_check.d ./Assembly/Collision_check.o ./Assembly/Copy_object.d ./Assembly/Copy_object.o ./Assembly/LFSR.d ./Assembly/LFSR.o ./Assembly/Random_0_to_6.d ./Assembly/Random_0_to_6.o ./Assembly/Rotate.d ./Assembly/Rotate.o ./Assembly/Write_piece_to_game_field.d ./Assembly/Write_piece_to_game_field.o ./Assembly/row_occupied.d ./Assembly/row_occupied.o

.PHONY: clean-Assembly

