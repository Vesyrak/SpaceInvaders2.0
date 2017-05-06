#ifndef SDLBASHER_H
#define SDLBASHER_H
#include "Basher.h"
#include "SDLContext.h"
class SDLBasher: public Basher{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBasher(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int movementSpeed);
        ~SDLBasher();
        void Visualise() override;
};
#endif
