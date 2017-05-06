#include "SDLLaser.h"
SDLLaser::SDLLaser(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage):Laser(x, y, movementSpeed, direction, damage){
    this->context=context;
    image=context->loadTexture("graphics/lasergreen.png");
}
SDLLaser::~SDLLaser(){
    SDL_DestroyTexture(image);
}

void SDLLaser::Visualise(){
    context->Draw(image, bounds);
}
