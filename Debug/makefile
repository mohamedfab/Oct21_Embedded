################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/04-APP/subdir.mk
-include Source/02-ECUA/SSD/Src/subdir.mk
-include Source/02-ECUA/Led/Src/subdir.mk
-include Source/02-ECUA/LCD/Src/subdir.mk
-include Source/02-ECUA/Keypad/Src/subdir.mk
-include Source/02-ECUA/Buzzer/Src/subdir.mk
-include Source/02-ECUA/Button/Src/subdir.mk
-include Source/01-MCAL/GINT/Src/subdir.mk
-include Source/01-MCAL/Dio/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Oct21_Amit_Interfacing
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Oct21_Amit_Interfacing.lss \

FLASH_IMAGE += \
Oct21_Amit_Interfacing.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: Oct21_Amit_Interfacing.elf secondary-outputs

# Tool invocations
Oct21_Amit_Interfacing.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Oct21_Amit_Interfacing.map -mmcu=atmega32 -o "Oct21_Amit_Interfacing.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Oct21_Amit_Interfacing.lss: Oct21_Amit_Interfacing.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Oct21_Amit_Interfacing.elf  >"Oct21_Amit_Interfacing.lss"
	@echo 'Finished building: $@'
	@echo ' '

Oct21_Amit_Interfacing.hex: Oct21_Amit_Interfacing.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Oct21_Amit_Interfacing.elf  "Oct21_Amit_Interfacing.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Oct21_Amit_Interfacing.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Oct21_Amit_Interfacing.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Oct21_Amit_Interfacing.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
