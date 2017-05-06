#include "SDLLaserBomb.h"
SDLLaserBomb::SDLLaserBomb(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage):LaserBomb(x, y, movementSpeed, direction, damage){
    this->context=context;
    image=context->loadTexture("graphics/bomberlaser.png");
}
SDLLaserBomb::~SDLLaserBomb(){
    SDL_DestroyTexture(image);
}

void SDLLaserBomb::Visualise(){
    context->Draw(image, bounds);
}
