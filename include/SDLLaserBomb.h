#ifndef SDLLASERBOMB_H
#define SDLLASERBOMB_H
#include "LaserBomb.h"
#include "SDLContext.h"
class SDLLaserBomb: public LaserBomb{
    public:
	SDLLaserBomb(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage);
        ~SDLLaserBomb();
        void Visualise() override;
    private:
        SDL_Texture* image;
        SDLContext* context;
};
#endif
