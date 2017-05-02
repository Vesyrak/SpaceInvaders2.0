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
#include "Projectile.h"
#include "Menu.h"
#include "Timer.h"
class AbstractFactory{
    public:
        virtual PlayerShip* createPlayerShip( std::vector<Entity*>* bulletVector, Input* input, int x, int y, int movementSpeed)=0;
        virtual Basher* createBasher(int x, int y, int movementSpeed)=0;
        virtual Blaster* createBlaster(int x, int y, int movementSpeed)=0;
        virtual Bomber* createBomber(int x, int y, int movementSpeed)=0;
        virtual Boss* createBoss(int x, int y, int movementSpeed)=0;
        virtual Window* createWindow(int screen_width, int screen_height)=0;
        virtual Input* createInputHandler()=0;
        virtual Background* createBackground()=0;
        virtual Projectile* createLaser(int x, int y, int movementSpeed, InputType direction, int damage)=0;//todo projectile shit
        virtual Menu* createMenu(Window* window)=0;
        virtual Timer* createTimer()=0;
};
#endif

