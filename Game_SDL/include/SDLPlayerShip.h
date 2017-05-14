#ifndef SDLPLAYERSHIP_H
#define SDLPLAYERSHIP_H
#include "PlayerShip.h"
#include "SDLContext.h"
using namespace std;
using namespace Game_Core;

namespace Game_SDL {

class SDLPlayerShip: public PlayerShip {
    private:
        SDL_Texture* image;
        SDLContext* context;

    public:
        SDLPlayerShip(AbstractFactory* factory,std::vector<Entity*>* bulletVector, SDLContext* context,int lives, int x, int y, int movementSpeed);
        ~SDLPlayerShip();
        void Visualise() override;
};}
#endif

