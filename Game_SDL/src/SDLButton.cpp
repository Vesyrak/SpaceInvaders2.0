#include "SDLButton.h"
namespace Game_SDL {

SDLButton::SDLButton(AbstractFactory* factory, SDLContext* context,
		std::string text, int x, int y) {
	borderBounds = new BoundingBox(x, y, 60, 20);
	buttonBounds = new BoundingBox(borderBounds->getX() + 1,
			borderBounds->getY() + 1, borderBounds->getWidth() - 2,
			borderBounds->getHeight() - 2);
	actualButtonBounds = new BoundingBox(x, y, 60, 20);
	context->LogicalToActualCoords(actualButtonBounds);
	mCurrentSprite = BUTTON_MOUSE_OUT;
	this->text = factory->createText(text, x + 1, y + 1);
	this->text->CenterText(buttonBounds);
	this->context = context;
	buttonColors[BUTTON_MOUSE_OUT*2]= {196,196,196,255};
	buttonColors[BUTTON_MOUSE_OUT*2+1]= {41,41,41,255};
	buttonColors[BUTTON_MOUSE_OVER_MOTION*2]= {196,196,196,255};
	buttonColors[BUTTON_MOUSE_OVER_MOTION*2+1]= {82,82,82,255};
	buttonColors[BUTTON_MOUSE_DOWN*2]= {82,82,82,255};
	buttonColors[BUTTON_MOUSE_DOWN*2+1]= {196,196,196,255};
}
SDLButton::~SDLButton() {
	delete borderBounds;
	delete buttonBounds;
	delete actualButtonBounds;
	delete text;
}

int SDLButton::handleEvent(SDL_Event* e) {
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN
			|| e->type == SDL_MOUSEBUTTONUP) {
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < actualButtonBounds->getX()) {
			inside = false;
		}
		//Mouse is right of the button
		else if (x
				> actualButtonBounds->getX() + actualButtonBounds->getWidth()) {
			inside = false;
		}
		//Mouse above the button
		else if (y < actualButtonBounds->getY()) {
			inside = false;
		}
		//Mouse below the button
		else if (y
				> actualButtonBounds->getY()
						+ actualButtonBounds->getHeight()) {
			inside = false;
		}
		//Mouse is outside button
		if (!inside) {
			mCurrentSprite = BUTTON_MOUSE_OUT;
		}
		//Mouse is inside button
		else {
			//Set mouse over sprite
			switch (e->type) {
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_MOUSE_OVER_MOTION;
				break;
			case SDL_MOUSEBUTTONDOWN:
				return 1;
				break;
				/*
				 case SDL_MOUSEBUTTONUP:
				 mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				 break;*/
			}
		}
	}
	return 0;
}
void SDLButton::Visualise() {
	context->DrawRect(&buttonColors[mCurrentSprite*2], borderBounds, true);
	context->DrawRect(&buttonColors[mCurrentSprite*2+1], buttonBounds, true);
	text->Visualise();
}
}
