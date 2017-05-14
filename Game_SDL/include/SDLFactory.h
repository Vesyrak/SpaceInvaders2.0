#ifndef SDLFACTORY_H
#define SDLFACTORY_H
#include "AbstractFactory.h"
#include "SDLPlayerShip.h"
#include "SDLBasher.h"
#include "SDLBlaster.h"
#include "SDLBomber.h"
#include "SDLBoss.h"
#include "SDLWindow.h"
#include "SDLInput.h"
#include "SDLContext.h"
#include "SDLBackground.h"
#include "SDLText.h"
#include "SDLLaser.h"
#include "SDLMenu.h"
#include "SDLTimer.h"
#include "SDLText.h"
#include "SDLLaserBomb.h"
#include "SDLHealthbar.h"
#include "SDLGameOverScreen.h"
#include "SDLSettingsScreen.h"
#include "SDLAudioEngine.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLFactory : public AbstractFactory{
    private:
    public:
		SDLFactory();
		~SDLFactory();
    	SDLContext* context;
        PlayerShip* createPlayerShip(std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed);
        Basher* createBasher(std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        Blaster* createBlaster(std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        Bomber* createBomber(std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        Boss* createBoss(int x, int y, int movementSpeed);
        Window* createWindow(int screen_width, int screen_height);
        Input* createInputHandler();
        Background* createBackground();
        Laser* createLaser( int x, int y, int movementSpeed, InputType direction, int damage);
        Screen* createMenu(Window* window);
        Timer* createTimer();
        Text* createText(std::string message, int x, int y);
        Text* createText(std::string message, int x, int y, int size);
        LaserBomb* createLaserBomb( int x, int y, int movementSpeed, InputType direction, int damage);
        Healthbar* createHealthbar(Entity* observed, int x, int y);
        Screen* createGameOverScreen(int score, Window* window);
        AudioEngine* getAudioEngine();
        Screen* createSettingsScreen(Window* window);
    private:
        AudioEngine* audioEngine;
};}
#endif

