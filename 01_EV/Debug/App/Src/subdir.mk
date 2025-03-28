################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/button.c \
../App/Src/buzzer.c \
../App/Src/i2c_lcd.c \
../App/Src/ir.c \
../App/Src/photo.c \
../App/Src/rc522.c \
../App/Src/rgb.c \
../App/Src/servo.c \
../App/Src/stepper.c 

OBJS += \
./App/Src/button.o \
./App/Src/buzzer.o \
./App/Src/i2c_lcd.o \
./App/Src/ir.o \
./App/Src/photo.o \
./App/Src/rc522.o \
./App/Src/rgb.o \
./App/Src/servo.o \
./App/Src/stepper.o 

C_DEPS += \
./App/Src/button.d \
./App/Src/buzzer.d \
./App/Src/i2c_lcd.d \
./App/Src/ir.d \
./App/Src/photo.d \
./App/Src/rc522.d \
./App/Src/rgb.d \
./App/Src/servo.d \
./App/Src/stepper.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su App/Src/%.cyclo: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/reon/workspace/STM32/Team_Project/01_EV/App/ap" -I"D:/reon/workspace/STM32/Team_Project/01_EV/App/common" -I"D:/reon/workspace/STM32/Team_Project/01_EV/App/hw" -I"D:/reon/workspace/STM32/Team_Project/01_EV/App/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/button.cyclo ./App/Src/button.d ./App/Src/button.o ./App/Src/button.su ./App/Src/buzzer.cyclo ./App/Src/buzzer.d ./App/Src/buzzer.o ./App/Src/buzzer.su ./App/Src/i2c_lcd.cyclo ./App/Src/i2c_lcd.d ./App/Src/i2c_lcd.o ./App/Src/i2c_lcd.su ./App/Src/ir.cyclo ./App/Src/ir.d ./App/Src/ir.o ./App/Src/ir.su ./App/Src/photo.cyclo ./App/Src/photo.d ./App/Src/photo.o ./App/Src/photo.su ./App/Src/rc522.cyclo ./App/Src/rc522.d ./App/Src/rc522.o ./App/Src/rc522.su ./App/Src/rgb.cyclo ./App/Src/rgb.d ./App/Src/rgb.o ./App/Src/rgb.su ./App/Src/servo.cyclo ./App/Src/servo.d ./App/Src/servo.o ./App/Src/servo.su ./App/Src/stepper.cyclo ./App/Src/stepper.d ./App/Src/stepper.o ./App/Src/stepper.su

.PHONY: clean-App-2f-Src

