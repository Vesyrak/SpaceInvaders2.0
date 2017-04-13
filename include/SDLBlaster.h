#ifndef SDLBLASTER_H
#define SDLBLASTER_H
#include "Blaster.h"
#include "SDLContext.h"
class SDLBlaster: public Blaster{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBlaster(SDLContext* context, int x, int y, int movementSpeed);
        ~SDLBlaster();
        void Visualise() override;
};
#endif
