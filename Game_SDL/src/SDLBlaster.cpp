#include "SDLBlaster.h"
namespace Game_SDL {

	SDLBlaster::SDLBlaster(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty) :
			Blaster(factory, bulletVector, x, y, difficulty) {
		this->context = context;
		image = context->GetTexture("graphics/enemy2.png");
	}
	SDLBlaster::~SDLBlaster() {
	}

	void SDLBlaster::Visualise() {
		context->Draw(image, bounds);
	}

}
