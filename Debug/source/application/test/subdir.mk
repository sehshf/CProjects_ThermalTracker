################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/application/test/test_irt.c \
../source/application/test/test_servo.c 

OBJS += \
./source/application/test/test_irt.o \
./source/application/test/test_servo.o 

C_DEPS += \
./source/application/test/test_irt.d \
./source/application/test/test_servo.d 


# Each subdirectory must supply rules for building sources it contributes
source/application/test/%.o: ../source/application/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\include" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot" -I"C:\SysGCC\Raspberry\arm-linux-gnueabihf\sysroot\usr\include" -I"C:\workspace\RaspberryPi\wiringPi-b0a60c3\wiringPi" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


