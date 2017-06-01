#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "PlayerShip.h"
#include "Basher.h"
#include "Blaster.h"
#include "Bomber.h"
#include "Window.h"
#include "Input.h"
#include "Background.h"
#include "Laser.h"
#include "Timer.h"
#include "Text.h"
#include "Healthbar.h"
#include "LaserBomb.h"
#include "Screen.h"
#include "AudioEngine.h"
#include "LifePowerUp.h"

namespace Game_Core {

    //Abstract class for initializing most important base classes
    class AbstractFactory {
    public:
        virtual ~AbstractFactory() {
        }
        virtual Basher *CreateBasher(std::vector<Entity *> *bulletVector, int x, int y, int movementSpeed)=0;
        virtual Blaster *CreateBlaster(std::vector<Entity *> *bulletVector, int x, int y, int movementSpeed)=0;
        virtual Bomber *CreateBomber(std::vector<Entity *> *bulletVector, int x, int y, int movementSpeed)=0;
        virtual PlayerShip *CreatePlayerShip(std::vector<Entity *> *bulletVector, int lives, int x, int y, int movementSpeed)=0;
        virtual Laser *CreateLaser(int x, int y, int movementSpeed, InputType direction, int damage)=0;
        virtual LaserBomb *CreateLaserBomb(int x, int y, int movementSpeed, InputType direction, int damage)=0;
        virtual LifePowerUp* CreateLifePowerUp(PlayerShip* playerShip, int x, int y)=0;
        virtual AudioEngine *GetAudioEngine()=0;
        virtual Input *GetInputHandler()=0;
        virtual Timer *CreateTimer()=0;
        virtual Background *CreateBackground()=0;
        virtual Healthbar *CreateHealthbar(Entity *observed, int x, int y)=0;
        virtual Text *CreateText(std::string message, int x, int y)=0;
        virtual Text *CreateText(std::string message, int x, int y, int size)=0;
        virtual Screen *CreateMenu(Window *window)=0;
        virtual Screen *CreateSettingsScreen(Window *window, std::string *username)=0;
        virtual Screen *CreateNextLevelScreen(int difficulty, Window *window)=0;
        virtual Screen *CreateGameOverScreen(std::string username, int score, Window *window)=0;
        virtual Window *CreateWindow(int screen_width, int screen_height)=0;
    };
}
#endif

