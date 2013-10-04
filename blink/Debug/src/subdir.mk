################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/audio_sample.c \
../src/main.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c \
../src/usb_bsp.c \
../src/usbh_usr.c \
../src/waveplayer.c \
../src/waverecorder.c 

OBJS += \
./src/audio_sample.o \
./src/main.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o \
./src/usb_bsp.o \
./src/usbh_usr.o \
./src/waveplayer.o \
./src/waverecorder.o 

C_DEPS += \
./src/audio_sample.d \
./src/main.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d \
./src/usb_bsp.d \
./src/usbh_usr.d \
./src/waveplayer.d \
./src/waverecorder.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -DUSE_USBOTG_DRIVER -DUSE_USB_OTG_HS -DUSE_EMBEDDED_PHY -DUSE_STM32F4_DISCOVERY -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DHSE_VALUE=8000000 -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\src" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32_USB_HOST_Library\Class\MSC\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Utilities\Third_Party\fat_fs\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32_USB_OTG_Driver\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32_USB_HOST_Library\Core\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Utilities\STM32F4-Discovery" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\STM32F4xx_StdPeriph_Driver\inc" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\CMSIS\ST\STM32F4xx\Include" -I"C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\Libraries\CMSIS\Include" -O0 -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


