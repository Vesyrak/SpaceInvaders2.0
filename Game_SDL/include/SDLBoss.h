#ifndef SDLBOSS_H
#define SDLBOSS_H
#include "Boss.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLBoss: public Boss{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBoss(SDLContext* context, int x, int y, int movementSpeed);
        ~SDLBoss();
        void Visualise() override;
};}
#endif