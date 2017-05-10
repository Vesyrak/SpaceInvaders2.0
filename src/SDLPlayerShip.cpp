#include <iostream>
#include "SDLPlayerShip.h"
SDLPlayerShip::SDLPlayerShip(AbstractFactory* factory,
		std::vector<Entity*>* bulletVector, Input* input, SDLContext* context,
		int x, int y, int movementSpeed) :
		PlayerShip(factory, bulletVector, input, x, y, movementSpeed) {
	this->context = context;
	image = context->getTexture("graphics/player_ship.png");
}
SDLPlayerShip::~SDLPlayerShip() {
}

void SDLPlayerShip::Visualise() {
	if (!invincible->isRunning()||(invincible->getTicks() / 250) % 2 == 1)
			context->Draw(image, bounds);

}
