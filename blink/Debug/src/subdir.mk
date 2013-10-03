################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f4_discovery.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/stm32f4_discovery.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/stm32f4_discovery.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DSTM32F4XX -I"C:\Users\Anthony.Paterson@opus.co\Documents\eclipse\STM32F4\Discovery\workspace\blink\src" -I"C:\Users\Anthony.Paterson@opus.co\Documents\eclipse\STM32F4\Discovery\workspace\blink\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\eclipse\STM32F4\Discovery\workspace\blink\Libraries\Device\STM32F4xx\Include" -I"C:\Users\Anthony.Paterson@opus.co\Documents\eclipse\STM32F4\Discovery\workspace\blink\Libraries\CMSIS\Include" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


