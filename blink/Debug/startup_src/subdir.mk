################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup_src/startup_stm32f4xx.S 

OBJS += \
./startup_src/startup_stm32f4xx.o 

S_UPPER_DEPS += \
./startup_src/startup_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
startup_src/%.o: ../startup_src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -DUSE_STM32F4_DISCOVERY -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DHSE_VALUE=8000000 -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\src" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Utilities\STM32F4-Discovery" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Device\STM32F4xx\Include" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\CMSIS\Include" -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


