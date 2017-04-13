#include "SDLBomber.h"
SDLBomber::SDLBomber(SDLContext* context, int x, int y, int movementSpeed):Bomber(x, y, movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/bomber.png");
}
SDLBomber::~SDLBomber(){
    SDL_DestroyTexture(image);
}

void SDLBomber::Visualise(){
    context->Draw(image, bounds);
}

