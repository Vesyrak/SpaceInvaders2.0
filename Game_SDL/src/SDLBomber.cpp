#include "SDLBomber.h"
namespace Game_SDL {

	SDLBomber::SDLBomber(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty) :Bomber(factory, bulletVector, x, y, difficulty) {
		this->context = context;
		image = context->GetTexture("graphics/bomber2.png");
		chargeImage = context->GetTexture("graphics/bomberlaser.png");
		chargeBounds = new BoundingBox(x, y, 4, 4);
	}

	SDLBomber::~SDLBomber() {
		delete chargeBounds;
	}

	//Draws the bomber. If it is charging it bullet, it will slowly enlarge and
	// shrink it.
	void SDLBomber::Visualise() {
		context->Draw(image, bounds);
		if (charging) {
			if ((timer->GetTicks() / 150) % 2 == 1) {
				chargeBounds->SetX(bounds->GetX() + bounds->GetWidth() / 2 - 2);
				chargeBounds->SetWidth(4);
				chargeBounds->SetHeight(4);
				chargeBounds->SetY(bounds->GetY());
			}
			else {
				chargeBounds->SetX(bounds->GetX() + bounds->GetWidth() / 2 - 1);
				chargeBounds->SetWidth(2);
				chargeBounds->SetHeight(2);
				chargeBounds->SetY(bounds->GetY() + 1);
			}
			context->Draw(chargeImage, chargeBounds);
		}
	}
}
