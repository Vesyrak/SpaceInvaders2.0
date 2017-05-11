#include "SDLLaserBomb.h"
namespace Game_SDL {

SDLLaserBomb::SDLLaserBomb(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage):LaserBomb(x, y, movementSpeed, direction, damage){
    this->context=context;
    image=context->getTexture("graphics/bomberlaser.png");
}
SDLLaserBomb::~SDLLaserBomb(){
}

void SDLLaserBomb::Visualise(){
    context->Draw(image, bounds);
}
}
