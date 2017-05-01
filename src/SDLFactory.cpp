#include "SDLFactory.h"
using namespace std;

PlayerShip* SDLFactory::createPlayerShip(std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed){
    return new SDLPlayerShip(this, bulletVector, input, context, x,  y,  movementSpeed);
}
Basher* SDLFactory::createBasher(int x, int y, int movementSpeed){
    return new SDLBasher(context, x,y,movementSpeed);
}
Blaster* SDLFactory::createBlaster(int x, int y, int movementSpeed){
    return new SDLBlaster(context, x,y, movementSpeed);
}
Bomber* SDLFactory::createBomber(int x, int y, int movementSpeed){
    return new SDLBomber(context, x,y,movementSpeed);
}

Boss* SDLFactory::createBoss(int x, int y, int movementSpeed){
    return new SDLBoss(context, x, y,movementSpeed);
}
Window* SDLFactory::createWindow(int screen_width, int screen_height){
    SDLWindow* window= new SDLWindow( screen_width, screen_height);
    this->context=new SDLContext(window);
    return window;
}
Input* SDLFactory::createInputHandler(){
    return new SDLInput();
}
Background* SDLFactory::createBackground(){
    return new SDLBackground(context);
}

Projectile* SDLFactory::createLaser(int x, int y, int movementSpeed, InputType direction, int damage){
	return new SDLLaser(context, x ,y, movementSpeed, direction, damage);
}
Menu* SDLFactory::createMenu(Window* window){
	return new SDLMenu(context,this,window);
}

