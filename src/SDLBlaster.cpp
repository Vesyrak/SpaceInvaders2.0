#include "SDLBlaster.h"
SDLBlaster::SDLBlaster(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty):Blaster(factory, bulletVector,x, y, difficulty){
    this->context=context;
    image=context->getTexture("graphics/blaster.png");
}
SDLBlaster::~SDLBlaster(){
}

void SDLBlaster::Visualise(){
    context->Draw(image, bounds);
}

