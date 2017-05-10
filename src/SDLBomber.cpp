#include "SDLBomber.h"
SDLBomber::SDLBomber(AbstractFactory* factory,
		std::vector<Entity*>* bulletVector, SDLContext* context, int x, int y,
		int difficulty) :
		Bomber(factory, bulletVector, x, y, difficulty) {
	this->context = context;
	image = context->getTexture("graphics/bomber.png");
	chargeImage = context->getTexture("graphics/bomberlaser.png");
	chargeBounds = new BoundingBox(x, y, 4, 4);
}
SDLBomber::~SDLBomber() {
	delete chargeBounds;
}

void SDLBomber::Visualise() {
	context->Draw(image, bounds);
	if (charging) {
		if ((timer->getTicks() / 150) % 2 == 1) {
			chargeBounds->setX(bounds->getX() + bounds->getWidth() / 2 - 2);
			chargeBounds->setWidth(4);
			chargeBounds->setHeight(4);
			chargeBounds->setY(bounds->getY());
		} else {
			chargeBounds->setX(bounds->getX() + bounds->getWidth() / 2 - 1);
			chargeBounds->setWidth(2);
			chargeBounds->setHeight(2);
			chargeBounds->setY(bounds->getY()+1);
		}
		context->Draw(chargeImage, chargeBounds);
	}
}

