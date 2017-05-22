#include "SDLTextBox.h"
namespace Game_SDL {
	SDLTextBox::SDLTextBox(SDLContext* context, AbstractFactory* factory, std::string* text, int x, int y) {
		content = text;
		historyContent = *text;
		bordercolor= {196,196,196,255};
		this->context = context;

		borderBounds = new BoundingBox(x, y, 60, 20);
		inputText = factory->CreateText(*content, x, y);
		inputText->CenterText(borderBounds);
	}
	SDLTextBox::~SDLTextBox() {
		delete inputText;
		delete borderBounds;
	}

	//Compares content to previous content, and updates accordingly.
	void SDLTextBox::HandleEvent(BaseInput* input) {
		if (*content != historyContent) {
			historyContent = *content;
			if (content->size() > 8)
				*content = content->substr(0, 8);
			if (content->size() != 0) {
				inputText->Update(*content);
				inputText->CenterText(borderBounds);
			}
		}

	}

	void SDLTextBox::Visualise() {
		context->DrawRect(&bordercolor, borderBounds, false);
		if (content->size() != 0)
			inputText->Visualise();
	}
}
