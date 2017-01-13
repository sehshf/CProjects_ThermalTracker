################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/basic/i2c_smbus.c \
../source/basic/pca9685.c 

OBJS += \
./source/basic/i2c_smbus.o \
./source/basic/pca9685.o 

C_DEPS += \
./source/basic/i2c_smbus.d \
./source/basic/pca9685.d 


# Each subdirectory must supply rules for building sources it contributes
source/basic/%.o: ../source/basic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\include" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot\usr\include" -I"C:\workspace\RaspberryPi\wiringPi-b0a60c3\wiringPi" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


