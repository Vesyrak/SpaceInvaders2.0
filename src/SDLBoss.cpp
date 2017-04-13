#include "SDLBoss.h"
SDLBoss::SDLBoss(SDLContext* context, int x, int y, int movementSpeed):Boss(x, y, movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/boss.png");
}
SDLBoss::~SDLBoss(){
    SDL_DestroyTexture(image);
}

void SDLBoss::Visualise(){
    context->Draw(image, bounds);
}

