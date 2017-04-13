#ifndef SDLPLAYERSHIP_H
#define SDLPLAYERSHIP_H
#include "PlayerShip.h"
#include "SDLContext.h"
using namespace std;
class SDLPlayerShip: public PlayerShip {
    private:
        SDL_Texture* image;
        SDLContext* context;

    public:
        SDLPlayerShip(SDLContext* context, int x, int y, int movementSpeed);
        ~SDLPlayerShip();
        void Visualise() override;
};
#endif

