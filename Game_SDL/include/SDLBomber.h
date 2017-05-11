#ifndef SDLBOMBER_H
#define SDLBOMBER_H
#include "Bomber.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLBomber: public Bomber{
    private:
        SDL_Texture* image;
        SDLContext* context;
        SDL_Texture* chargeImage;
        BoundingBox* chargeBounds;
    public:
        SDLBomber(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty);
        ~SDLBomber();
        void Visualise() override;
};}
#endif
