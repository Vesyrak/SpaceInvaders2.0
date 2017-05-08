################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Background.cpp \
../src/Basher.cpp \
../src/Blaster.cpp \
../src/Bomber.cpp \
../src/Boss.cpp \
../src/BoundingBox.cpp \
../src/Entity.cpp \
../src/Game.cpp \
../src/Healthbar.cpp \
../src/Laser.cpp \
../src/LaserBomb.cpp \
../src/Level.cpp \
../src/Menu.cpp \
../src/PlayerShip.cpp \
../src/SDLAudioEngine.cpp \
../src/SDLBackground.cpp \
../src/SDLBasher.cpp \
../src/SDLBlaster.cpp \
../src/SDLBomber.cpp \
../src/SDLBoss.cpp \
../src/SDLButton.cpp \
../src/SDLContext.cpp \
../src/SDLFactory.cpp \
../src/SDLGameOverScreen.cpp \
../src/SDLHealthbar.cpp \
../src/SDLInput.cpp \
../src/SDLLaser.cpp \
../src/SDLLaserBomb.cpp \
../src/SDLMenu.cpp \
../src/SDLPlayerShip.cpp \
../src/SDLText.cpp \
../src/SDLTimer.cpp \
../src/SDLWindow.cpp \
../src/Screen.cpp \
../src/Text.cpp \
../src/Timer.cpp \
../src/Window.cpp \
../src/main.cpp 

OBJS += \
./src/Background.o \
./src/Basher.o \
./src/Blaster.o \
./src/Bomber.o \
./src/Boss.o \
./src/BoundingBox.o \
./src/Entity.o \
./src/Game.o \
./src/Healthbar.o \
./src/Laser.o \
./src/LaserBomb.o \
./src/Level.o \
./src/Menu.o \
./src/PlayerShip.o \
./src/SDLAudioEngine.o \
./src/SDLBackground.o \
./src/SDLBasher.o \
./src/SDLBlaster.o \
./src/SDLBomber.o \
./src/SDLBoss.o \
./src/SDLButton.o \
./src/SDLContext.o \
./src/SDLFactory.o \
./src/SDLGameOverScreen.o \
./src/SDLHealthbar.o \
./src/SDLInput.o \
./src/SDLLaser.o \
./src/SDLLaserBomb.o \
./src/SDLMenu.o \
./src/SDLPlayerShip.o \
./src/SDLText.o \
./src/SDLTimer.o \
./src/SDLWindow.o \
./src/Screen.o \
./src/Text.o \
./src/Timer.o \
./src/Window.o \
./src/main.o 

CPP_DEPS += \
./src/Background.d \
./src/Basher.d \
./src/Blaster.d \
./src/Bomber.d \
./src/Boss.d \
./src/BoundingBox.d \
./src/Entity.d \
./src/Game.d \
./src/Healthbar.d \
./src/Laser.d \
./src/LaserBomb.d \
./src/Level.d \
./src/Menu.d \
./src/PlayerShip.d \
./src/SDLAudioEngine.d \
./src/SDLBackground.d \
./src/SDLBasher.d \
./src/SDLBlaster.d \
./src/SDLBomber.d \
./src/SDLBoss.d \
./src/SDLButton.d \
./src/SDLContext.d \
./src/SDLFactory.d \
./src/SDLGameOverScreen.d \
./src/SDLHealthbar.d \
./src/SDLInput.d \
./src/SDLLaser.d \
./src/SDLLaserBomb.d \
./src/SDLMenu.d \
./src/SDLPlayerShip.d \
./src/SDLText.d \
./src/SDLTimer.d \
./src/SDLWindow.d \
./src/Screen.d \
./src/Text.d \
./src/Timer.d \
./src/Window.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/reinout/repos/SpaceInvaders2.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


