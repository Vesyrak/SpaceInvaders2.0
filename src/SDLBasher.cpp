#include "SDLBasher.h"
SDLBasher::SDLBasher(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty):Basher(factory, bulletVector,x,y,difficulty){
    this->context=context;
    image=context->loadTexture("graphics/basher.png");
}
SDLBasher::~SDLBasher(){
    SDL_DestroyTexture(image);
}

void SDLBasher::Visualise(){
    context->Draw(image, bounds);
}

