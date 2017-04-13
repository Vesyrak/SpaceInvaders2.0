#ifndef SDLBOMBER_H
#define SDLBOMBER_H
#include "Bomber.h"
#include "SDLContext.h"
class SDLBomber: public Bomber{
    private:
        SDL_Texture* image;
        SDLContext* context;
    public:
        SDLBomber(SDLContext* context, int x, int y, int movementSpeed);
        ~SDLBomber();
        void Visualise() override;
};
#endif
