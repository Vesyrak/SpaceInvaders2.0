#include "SDLLifePowerUp.h"
namespace Game_SDL {

	SDLLifePowerUp::SDLLifePowerUp(SDLContext* context, PlayerShip* playerShip, int x, int y):LifePowerUp(playerShip,x, y) {
		this->context = context;
		image = context->GetTexture("graphics/life2.png");
	}
	SDLLifePowerUp::~SDLLifePowerUp() {
	}

	void SDLLifePowerUp::Visualise() {
		context->Draw(image, bounds);
	}

}
