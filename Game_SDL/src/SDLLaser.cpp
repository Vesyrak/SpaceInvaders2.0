#include "SDLLaser.h"
namespace Game_SDL {

	SDLLaser::SDLLaser(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage) :
			Laser(x, y, movementSpeed, direction, damage) {
		this->context = context;
		image = context->GetTexture("graphics/lasergreen.png");
	}
	SDLLaser::~SDLLaser() {
	}

	void SDLLaser::Visualise() {
		context->Draw(image, bounds);
	}
}
