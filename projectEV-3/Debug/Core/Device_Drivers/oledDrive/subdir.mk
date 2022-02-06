################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Device_Drivers/oledDrive/ssd1306.c \
../Core/Device_Drivers/oledDrive/ssd1306_fonts.c \
../Core/Device_Drivers/oledDrive/ssd1306_tests.c 

C_DEPS += \
./Core/Device_Drivers/oledDrive/ssd1306.d \
./Core/Device_Drivers/oledDrive/ssd1306_fonts.d \
./Core/Device_Drivers/oledDrive/ssd1306_tests.d 

OBJS += \
./Core/Device_Drivers/oledDrive/ssd1306.o \
./Core/Device_Drivers/oledDrive/ssd1306_fonts.o \
./Core/Device_Drivers/oledDrive/ssd1306_tests.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Device_Drivers/oledDrive/%.o: ../Core/Device_Drivers/oledDrive/%.c Core/Device_Drivers/oledDrive/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/MY_FILES/myProjects/GITHUB/projectEV-3/projectEV-3/Core/Device_Drivers/oledDrive" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Device_Drivers-2f-oledDrive

clean-Core-2f-Device_Drivers-2f-oledDrive:
	-$(RM) ./Core/Device_Drivers/oledDrive/ssd1306.d ./Core/Device_Drivers/oledDrive/ssd1306.o ./Core/Device_Drivers/oledDrive/ssd1306_fonts.d ./Core/Device_Drivers/oledDrive/ssd1306_fonts.o ./Core/Device_Drivers/oledDrive/ssd1306_tests.d ./Core/Device_Drivers/oledDrive/ssd1306_tests.o

.PHONY: clean-Core-2f-Device_Drivers-2f-oledDrive

