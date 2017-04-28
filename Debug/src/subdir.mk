################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game3.cpp \
../src/player.cpp \
../src/rect.cpp \
../src/window.cpp 

OBJS += \
./src/Game3.o \
./src/player.o \
./src/rect.o \
./src/window.o 

CPP_DEPS += \
./src/Game3.d \
./src/player.d \
./src/rect.d \
./src/window.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


