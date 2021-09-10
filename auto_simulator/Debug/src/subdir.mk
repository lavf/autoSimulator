################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/JsonFile.cpp \
../src/TextFile.cpp \
../src/autoSimulator.cpp \
../src/autoSimulatorUtil.cpp 

OBJS += \
./src/JsonFile.o \
./src/TextFile.o \
./src/autoSimulator.o \
./src/autoSimulatorUtil.o 

CPP_DEPS += \
./src/JsonFile.d \
./src/TextFile.d \
./src/autoSimulator.d \
./src/autoSimulatorUtil.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


