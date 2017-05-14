#include <iostream>
#include "SDLPlayerShip.h"
namespace Game_SDL {

SDLPlayerShip::SDLPlayerShip(AbstractFactory* factory,
		std::vector<Entity*>* bulletVector, SDLContext* context,
		int lives, int x, int y, int movementSpeed) :
		PlayerShip(factory, bulletVector, lives, x, y, movementSpeed) {
	this->context = context;
	image = context->getTexture("graphics/player_ship.png");
}
SDLPlayerShip::~SDLPlayerShip() {
}

void SDLPlayerShip::Visualise() {
	if (!invincible->isRunning()||(invincible->getTicks() / 250) % 2 == 1)
			context->Draw(image, bounds);

}
}
