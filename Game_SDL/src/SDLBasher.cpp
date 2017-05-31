#include "SDLBasher.h"
namespace Game_SDL {

	SDLBasher::SDLBasher(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty) :
			Basher(factory, bulletVector, x, y, difficulty) {
		this->context = context;
		image = context->GetTexture("graphics/enemy1.png");
	}
	SDLBasher::~SDLBasher() {
	}

	void SDLBasher::Visualise() {
		context->Draw(image, bounds);
	}

}
