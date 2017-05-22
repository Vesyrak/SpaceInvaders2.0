#include "SDLButton.h"
namespace Game_SDL {

	SDLButton::SDLButton(SDLContext* context, AbstractFactory* factory, std::string text, int x, int y) {
		borderBounds = new BoundingBox(x, y, 60, 20);
		buttonBounds = new BoundingBox(borderBounds->GetX() + 1, borderBounds->GetY() + 1, borderBounds->GetWidth() - 2, borderBounds->GetHeight() - 2);
		actualButtonBounds = new BoundingBox(x, y, 60, 20);
		context->LogicalToActualCoords(actualButtonBounds);
		mCurrentSprite = BUTTON_MOUSE_OUT;
		this->text = factory->CreateText(text, x + 1, y + 1);
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

	// Handles mouse location for the button handling
	int SDLButton::HandleEvent(SDL_Event* e) {
		//If there's a mouse event
		if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
			//Get state
			int x, y;
			SDL_GetMouseState(&x, &y);
			bool inside = true;
			//Compare with button's bounds
			if (x < actualButtonBounds->GetX()) {
				inside = false;
			}
			else if (x > actualButtonBounds->GetX() + actualButtonBounds->GetWidth()) {
				inside = false;
			}
			else if (y < actualButtonBounds->GetY()) {
				inside = false;
			}
			else if (y > actualButtonBounds->GetY() + actualButtonBounds->GetHeight()) {
				inside = false;
			}
			if (!inside) {
				mCurrentSprite = BUTTON_MOUSE_OUT;
			}
			else {
				switch (e->type) {
					case SDL_MOUSEMOTION:
						mCurrentSprite = BUTTON_MOUSE_OVER_MOTION;
						break;
					case SDL_MOUSEBUTTONDOWN:
						return 1;
						break;
				}
			}
		}
		return 0;
	}

	void SDLButton::Visualise() {
		context->DrawRect(&buttonColors[mCurrentSprite * 2], borderBounds, true);
		context->DrawRect(&buttonColors[mCurrentSprite * 2 + 1], buttonBounds, true);
		text->Visualise();
	}
}
