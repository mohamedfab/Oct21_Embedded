################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/02-ECUA/Led/Src/Led.c 

OBJS += \
./Source/02-ECUA/Led/Src/Led.o 

C_DEPS += \
./Source/02-ECUA/Led/Src/Led.d 


# Each subdirectory must supply rules for building sources it contributes
Source/02-ECUA/Led/Src/%.o: ../Source/02-ECUA/Led/Src/%.c Source/02-ECUA/Led/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\Oct21_Embedded\Source\00-Lib" -I"F:\Oct21_Embedded\Source\02-ECUA\Button\Inc" -I"F:\Oct21_Embedded\Source\02-ECUA\Led\Inc" -I"F:\Oct21_Embedded\Source\01-MCAL\Dio\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

