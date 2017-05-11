#ifndef SDLBLASTER_H
#define SDLBLASTER_H
#include "Blaster.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL {

class SDLBlaster: public Blaster{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBlaster(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty);
        ~SDLBlaster();
        void Visualise() override;
};}

#endif
