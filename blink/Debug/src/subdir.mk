################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STM32F4_DISCOVERY -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DHSE_VALUE=8000000 -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\src" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Utilities\STM32F4-Discovery" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Device\STM32F4xx\Include" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\CMSIS\Include" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


