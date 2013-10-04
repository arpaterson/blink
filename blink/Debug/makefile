################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := cs-rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup_src/subdir.mk
-include src/subdir.mk
-include Utilities/Third_Party/fat_fs/src/option/subdir.mk
-include Utilities/Third_Party/fat_fs/src/subdir.mk
-include Utilities/STM32F4-Discovery/subdir.mk
-include Libraries/STM32_USB_OTG_Driver/src/subdir.mk
-include Libraries/STM32_USB_HOST_Library/Core/src/subdir.mk
-include Libraries/STM32_USB_HOST_Library/Class/MSC/src/subdir.mk
-include Libraries/STM32_USB_HOST_Library/Class/HID/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Core/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Class/msc/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Class/hid/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Class/dfu/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Class/cdc/src/subdir.mk
-include Libraries/STM32_USB_Device_Library/Class/audio/src/subdir.mk
-include Libraries/STM32F4xx_StdPeriph_Driver/src/subdir.mk
-include Libraries/CMSIS/ST/STM32F4xx/Source/Templates/TASKING/subdir.mk
-include Libraries/CMSIS/ST/STM32F4xx/Source/Templates/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/TransformFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/SupportFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/StatisticsFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/MatrixFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/FilteringFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/FastMathFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/ControllerFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/ComplexMathFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/CommonTables/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Source/BasicMathFunctions/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_variance_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_sin_cos_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_signal_converge_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_matrix_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_linear_interp_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_graphic_equalizer_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_fir_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_fft_bin_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_dotproduct_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_convolution_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/arm_class_marks_example/subdir.mk
-include Libraries/CMSIS/DSP_Lib/Examples/Common/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
blink.hex \

SECONDARY_LIST += \
blink.lst \

SECONDARY_SIZE += \
blink.siz \


# All Target
all: blink.elf secondary-outputs

# Tool invocations
blink.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Windows GCC C Linker'
	arm-none-eabi-gcc -T""C:\Users\Anthony.Paterson@opus.co\Documents\git\blink\blink\stm32_flash.ld"" -Xlinker --gc-sections -Wl,-Map,"blink.map" -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "blink.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

blink.hex: blink.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "blink.elf"  "blink.hex"
	@echo 'Finished building: $@'
	@echo ' '

blink.lst: blink.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Listing'
	arm-none-eabi-objdump -h -S "blink.elf" > "blink.lst"
	@echo 'Finished building: $@'
	@echo ' '

blink.siz: blink.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Print Size'
	arm-none-eabi-size  --format=berkeley "blink.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) blink.elf
	-@echo ' '

post-build:
	-@echo 'Binary'
	-arm-none-eabi-objcopy -S  -O binary  "blink.elf" "blink.bin"
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
