#include "SDLBlaster.h"
SDLBlaster::SDLBlaster(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int movementSpeed):Blaster(factory, bulletVector,x, y, movementSpeed){
    this->context=context;
    image=context->loadTexture("graphics/blaster.png");
}
SDLBlaster::~SDLBlaster(){
    SDL_DestroyTexture(image);
}

void SDLBlaster::Visualise(){
    context->Draw(image, bounds);
}

