#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "PlayerShip.h"
#include "Basher.h"
#include "Blaster.h"
#include "Bomber.h"
#include "Boss.h"
#include "Window.h"
#include "Input.h"
#include "Background.h"
class AbstractFactory{
    public:
        virtual PlayerShip* createPlayerShip(int x, int y, int movementSpeed)=0;
        virtual Basher* createBasher(int x, int y, int movementSpeed)=0;
        virtual Blaster* createBlaster(int x, int y, int movementSpeed)=0;
        virtual Bomber* createBomber(int x, int y, int movementSpeed)=0;
        virtual Boss* createBoss(int x, int y, int movementSpeed)=0;
        virtual Window* createWindow(int screen_width, int screen_height)=0;
        virtual Input* createInputHandler()=0;
        virtual Background* createBackground()=0;
};
#endif

