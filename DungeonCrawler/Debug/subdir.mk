################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Character.cpp \
../DungeonMap.cpp \
../GameEngine.cpp \
../Tile.cpp \
../main.cpp 

OBJS += \
./Character.o \
./DungeonMap.o \
./GameEngine.o \
./Tile.o \
./main.o 

CPP_DEPS += \
./Character.d \
./DungeonMap.d \
./GameEngine.d \
./Tile.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


