#include "SDLText.h"

namespace Game_SDL {

	SDLText::SDLText(SDLContext* context, std::string message, int x, int y, int size) :
			Text(message, x, y, size) {
		this->context = context;
		this->texture = this->context->GenerateText(message, bounds, size);
	}

	SDLText::SDLText(SDLContext* context, std::string message, int x, int y):SDLText(context, message, x, y, context->defaultFontSize) {

	}

	SDLText::~SDLText() {
		SDL_DestroyTexture(texture);
	}

	//Regenerates text with new message
	void SDLText::Update(std::string message) {
		SDL_DestroyTexture(texture);
		this->texture = this->context->GenerateText(message, bounds, size);

	}

	void SDLText::Visualise() {
		context->Draw(texture, bounds);
	}

	void SDLText::CenterText(BoundingBox* outerBounds) {

		bounds->SetX(outerBounds->GetX() + (outerBounds->GetWidth() - bounds->GetWidth()) / 2);
		bounds->SetY(outerBounds->GetY() + (outerBounds->GetHeight() - bounds->GetHeight()) / 2);
	}

	void SDLText::HorizontalCenterText(int x, int width) {
		bounds->SetX(x + (width - bounds->GetWidth()) / 2);
	}

	void SDLText::VerticalCenterText(int y, int height) {
		bounds->SetY(y + (height - bounds->GetHeight()) / 2);

	}
}
