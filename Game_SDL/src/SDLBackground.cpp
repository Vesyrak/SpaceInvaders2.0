#include "SDLBackground.h"
namespace Game_SDL {

	SDLBackground::SDLBackground(SDLContext* context) :
			Background() {
		this->context = context;
		image = context->GetTexture("graphics/background.png");
		scrollingOffset = 0;
		scrollBounds = new BoundingBox(0, 0, 200, 200);
	}

	SDLBackground::~SDLBackground() {
		delete scrollBounds;
	}

	//Scrolls the background (optional)
	void SDLBackground::Update() {
		int offset = bounds->GetY();
		bounds->SetY((double) ++offset);
		scrollBounds->SetY((double) (bounds->GetY() - bounds->GetHeight()));
		if (bounds->GetY() > bounds->GetHeight()) {
			bounds->SetY(0);
		}
	}

	void SDLBackground::Visualise() {
		context->Draw(image, bounds);
		context->Draw(image, scrollBounds);
	}
}
