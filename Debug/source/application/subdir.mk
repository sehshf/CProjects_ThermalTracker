################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/application/common.c \
../source/application/irt_sensor.c \
../source/application/main.c \
../source/application/servo_motor.c 

OBJS += \
./source/application/common.o \
./source/application/irt_sensor.o \
./source/application/main.o \
./source/application/servo_motor.o 

C_DEPS += \
./source/application/common.d \
./source/application/irt_sensor.d \
./source/application/main.d \
./source/application/servo_motor.d 


# Each subdirectory must supply rules for building sources it contributes
source/application/%.o: ../source/application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\include" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot\usr\include" -I"C:\workspace\RaspberryPi\wiringPi-b0a60c3\wiringPi" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


