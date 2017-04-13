#include "SDLBasher.h"
SDLBasher::SDLBasher(SDLContext* context, int x, int y, int movementSpeed):Basher(x,y,movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/basher.png");
}
SDLBasher::~SDLBasher(){
    SDL_DestroyTexture(image);
}

void SDLBasher::Visualise(){
    context->Draw(image, bounds);
}

