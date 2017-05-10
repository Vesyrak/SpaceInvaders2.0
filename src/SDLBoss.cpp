#include "SDLBoss.h"
SDLBoss::SDLBoss(SDLContext* context, int x, int y, int movementSpeed):Boss(x, y, movementSpeed){
    this->context=context;
    image=context->getTexture("graphics/boss.png");
}
SDLBoss::~SDLBoss(){
}

void SDLBoss::Visualise(){
    context->Draw(image, bounds);
}

