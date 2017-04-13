#include <iostream>
#include "SDLPlayerShip.h"
SDLPlayerShip::SDLPlayerShip(SDLContext* context, int x, int y, int movementSpeed):PlayerShip(x, y, movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/player_ship.png");
}
SDLPlayerShip::~SDLPlayerShip(){
    SDL_DestroyTexture(image);
}

void SDLPlayerShip::Visualise(){
    context->Draw(image, bounds);
}

