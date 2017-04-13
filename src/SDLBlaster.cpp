#include "SDLBlaster.h"
SDLBlaster::SDLBlaster(SDLContext* context, int x, int y, int movementSpeed):Blaster(x, y, movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/blaster.png");
}
SDLBlaster::~SDLBlaster(){
    SDL_DestroyTexture(image);
}

void SDLBlaster::Visualise(){
    context->Draw(image, bounds);
}

