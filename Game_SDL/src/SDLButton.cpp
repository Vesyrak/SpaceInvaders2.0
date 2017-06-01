#include "SDLButton.h"
namespace Game_SDL {

	//Constructor setting standard parameters, bounding boxes and colors for hovering
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
	int SDLButton::HandleEvent(BaseInput* input) {
		//If there's a mouse event
		if (input->mouseX != -1) {
			bool inside = true;
			//Compare with button's bounds
			if (input->mouseX < actualButtonBounds->GetX()) {
				inside = false;
			}
			else if (input->mouseX > actualButtonBounds->GetX() + actualButtonBounds->GetWidth()) {
				inside = false;
			}
			else if (input->mouseY < actualButtonBounds->GetY()) {
				inside = false;
			}
			else if (input->mouseY > actualButtonBounds->GetY() + actualButtonBounds->GetHeight()) {
				inside = false;
			}
			if (!inside) {
				mCurrentSprite = BUTTON_MOUSE_OUT;
			}
			else if (input->mousepress) {
				return 1;
			}
			else {
				mCurrentSprite = BUTTON_MOUSE_OVER_MOTION;
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
