#include "SDLBasher.h"
namespace Game_SDL {

SDLBasher::SDLBasher(AbstractFactory* factory,std::vector<Entity*>* bulletVector,SDLContext* context, int x, int y, int difficulty):Basher(factory, bulletVector,x,y,difficulty){
    this->context=context;
    image=context->getTexture("graphics/basher.png");
}
SDLBasher::~SDLBasher(){
}

void SDLBasher::Visualise(){
    context->Draw(image, bounds);
}

}