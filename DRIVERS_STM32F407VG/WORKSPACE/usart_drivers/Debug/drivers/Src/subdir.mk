################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/gpio.c \
../drivers/Src/rcc.c \
../drivers/Src/spi.c \
../drivers/Src/uart.c 

OBJS += \
./drivers/Src/gpio.o \
./drivers/Src/rcc.o \
./drivers/Src/spi.o \
./drivers/Src/uart.o 

C_DEPS += \
./drivers/Src/gpio.d \
./drivers/Src/rcc.d \
./drivers/Src/spi.d \
./drivers/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/gpio.o: ../drivers/Src/gpio.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Navjeevan/OneDrive/Documents/GitHub/baremetalSTM32DISC1/DRIVERS_STM32F407VG/WORKSPACE/usart_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/rcc.o: ../drivers/Src/rcc.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Navjeevan/OneDrive/Documents/GitHub/baremetalSTM32DISC1/DRIVERS_STM32F407VG/WORKSPACE/usart_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/rcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/spi.o: ../drivers/Src/spi.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Navjeevan/OneDrive/Documents/GitHub/baremetalSTM32DISC1/DRIVERS_STM32F407VG/WORKSPACE/usart_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/spi.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
drivers/Src/uart.o: ../drivers/Src/uart.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/Navjeevan/OneDrive/Documents/GitHub/baremetalSTM32DISC1/DRIVERS_STM32F407VG/WORKSPACE/usart_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

