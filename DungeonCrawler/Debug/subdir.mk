################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Character.cpp \
../DungeonMap.cpp \
../Floor.cpp \
../GameEngine.cpp \
../Tile.cpp \
../Wall.cpp \
../main.cpp 

OBJS += \
./Character.o \
./DungeonMap.o \
./Floor.o \
./GameEngine.o \
./Tile.o \
./Wall.o \
./main.o 

CPP_DEPS += \
./Character.d \
./DungeonMap.d \
./Floor.d \
./GameEngine.d \
./Tile.d \
./Wall.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


