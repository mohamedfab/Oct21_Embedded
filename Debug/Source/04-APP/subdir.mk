################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/04-APP/main.c 

OBJS += \
./Source/04-APP/main.o 

C_DEPS += \
./Source/04-APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source/04-APP/%.o: ../Source/04-APP/%.c Source/04-APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Oct21_Embedded\Source\00-Lib" -I"F:\Oct21_Embedded\Source\02-ECUA\Button\Inc" -I"F:\Oct21_Embedded\Source\02-ECUA\Led\Inc" -I"F:\Oct21_Embedded\Source\01-MCAL\Dio\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

