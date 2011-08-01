################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FSArea.cpp \
../src/FSDriver.cpp 

OBJS += \
./src/FSArea.o \
./src/FSDriver.o 

CPP_DEPS += \
./src/FSArea.d \
./src/FSDriver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/user/workspace/cpp/DiskCache/CrossPthread/src -I/home/user/workspace/cpp/DiskCache/CrossFile/src -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


