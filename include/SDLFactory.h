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
class SDLFactory : public AbstractFactory{
    private:
        SDLContext* context;
    public:
        PlayerShip* createPlayerShip(int x, int y, int movementSpeed);
        Basher* createBasher(int x, int y, int movementSpeed);
        Blaster* createBlaster(int x, int y, int movementSpeed);
        Bomber* createBomber(int x, int y, int movementSpeed);
        Boss* createBoss(int x, int y, int movementSpeed);
        Window* createWindow(int screen_width, int screen_height);
        Input* createInputHandler();
};
#endif

