#include "SDLLaser.h"
SDLLaser::SDLLaser(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage):Projectile(x, y, movementSpeed, direction, damage){
    this->context=context;
    image=context->loadTexture("graphics/laserb.png");
}
SDLLaser::~SDLLaser(){
    SDL_DestroyTexture(image);
}

void SDLLaser::Visualise(){
    context->Draw(image, bounds);
}
