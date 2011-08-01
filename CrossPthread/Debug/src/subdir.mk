################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CrossPthreadMutex.cpp \
../src/CrossPthreadRWLock.cpp 

OBJS += \
./src/CrossPthreadMutex.o \
./src/CrossPthreadRWLock.o 

CPP_DEPS += \
./src/CrossPthreadMutex.d \
./src/CrossPthreadRWLock.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -pthread -fPIC -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


