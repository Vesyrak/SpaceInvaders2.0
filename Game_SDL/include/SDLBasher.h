#ifndef SDLBASHER_H
#define SDLBASHER_H
#include "Basher.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL {
class SDLBasher: public Basher{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBasher(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty);
        ~SDLBasher();
        void Visualise() override;
};}
#endif
