#include <iostream>
#include "SDLPlayerShip.h"
namespace Game_SDL {

	SDLPlayerShip::SDLPlayerShip(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed) :PlayerShip(factory, bulletVector, lives, x, y, movementSpeed) {
		this->context = context;
		image = context->GetTexture("graphics/playership2.png");
	}
	SDLPlayerShip::~SDLPlayerShip() {
	}

	void SDLPlayerShip::Visualise() {
		if (!invincible->IsRunning() || (invincible->GetTicks() / 250) % 2 == 1)
			context->Draw(image, bounds);

	}
}
