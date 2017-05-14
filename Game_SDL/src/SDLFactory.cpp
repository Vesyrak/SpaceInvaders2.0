#include "SDLFactory.h"
using namespace std;
namespace Game_SDL {

SDLFactory::SDLFactory(){
	audioEngine=NULL;
	context=NULL;
}
SDLFactory::~SDLFactory(){
	delete context;
}
PlayerShip* SDLFactory::createPlayerShip(std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed){
return new SDLPlayerShip(this, bulletVector, input, context, x,  y,  movementSpeed);
}
Basher* SDLFactory::createBasher(std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed){
    return new SDLBasher(this, bulletVector,context, x,y,movementSpeed);
}
Blaster* SDLFactory::createBlaster(std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed){
    return new SDLBlaster(this, bulletVector,context, x,y, movementSpeed);
}
Bomber* SDLFactory::createBomber(std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed){
    return new SDLBomber(this, bulletVector,context, x,y,movementSpeed);
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

Laser* SDLFactory::createLaser(int x, int y, int movementSpeed, InputType direction, int damage){
	return new SDLLaser(context, x ,y, movementSpeed, direction, damage);
}
Screen* SDLFactory::createMenu(Window* window){
	return new SDLMenu(context,this,window);
}
Timer* SDLFactory::createTimer(){
	return new SDLTimer();
}
Text* SDLFactory::createText(std::string message, int x, int y){
	return new SDLText( context, message, x, y);
}
Text* SDLFactory::createText(std::string message, int x, int y, int size){
	return new SDLText( context, message, x, y, size);
}
LaserBomb* SDLFactory::createLaserBomb( int x, int y, int movementSpeed, InputType direction, int damage){
	return new SDLLaserBomb(context, x, y, movementSpeed, direction, damage);
}
Healthbar* SDLFactory::createHealthbar(Entity* observed, int x, int y){
	return new SDLHealthbar(this, context, observed, x,y);
}
Screen* SDLFactory::createGameOverScreen(int score, Window* window){
	return new SDLGameOverScreen(score, context,this, window);
}
AudioEngine* SDLFactory::getAudioEngine(){
	if(audioEngine==NULL){
		audioEngine= new SDLAudioEngine();
	}
	return audioEngine;
}
Screen* SDLFactory::createSettingsScreen(Window* window){
	return new SDLSettingsScreen(this,context, window);
}

}
