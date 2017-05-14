#include "SDLTextBox.h"
namespace Game_SDL {
SDLTextBox::SDLTextBox(AbstractFactory* factory, SDLContext* context,std::string* text, int x, int y) {
	content = text;
	historyContent=*text;
	this->context = context;
	borderBounds = new BoundingBox(x, y, 60, 20);
	inputText = factory->createText(*content, x, y);
	inputText->CenterText(borderBounds);
	bordercolor= {196,196,196,255};
}
SDLTextBox::~SDLTextBox() {
	delete inputText;
	delete borderBounds;
}
void SDLTextBox::handleEvent(SDL_Event *e) {
	getCharacterInput(e);
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
void SDLTextBox::getCharacterInput(SDL_Event* e) {

		if (e->type == SDL_KEYDOWN) {
			//Handle backspace
			if (e->key.keysym.sym == SDLK_BACKSPACE && content->length() > 0) {
				//lop off character
				content->pop_back();
			}
		}
		if (e->type == SDL_TEXTINPUT) {
			//Append character
			content->append(e->text.text);
		}
}
void SDLTextBox::Visualise() {
	context->DrawRect(&bordercolor, borderBounds, false);
	if (content->size() != 0)
		inputText->Visualise();
}
}
