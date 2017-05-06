#ifndef SDLLASER_H
#define SDLLASER_H
#include "Laser.h"
#include "SDLContext.h"
class SDLLaser: public Laser{
    public:
        SDLLaser(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage);
        ~SDLLaser();
        void Visualise() override;
    private:
        InputType direction;
        int damage;
        SDL_Texture* image;
        SDLContext* context;
};
#endif
