#ifndef SDLTEXTBOX_H
#define SDLTEXTBOX_H
#include "Text.h"
#include "AbstractFactory.h"
#include "SDLContext.h"
#include "BaseInput.h"
using namespace Game_Core;
namespace Game_SDL {

	//SDL Text Box
	class SDLTextBox {
		public:
			SDLTextBox(SDLContext* context, AbstractFactory* factory, std::string* text, int x, int y);
			~SDLTextBox();
			void Visualise();
			void HandleEvent(BaseInput* input);
			std::string* content;
		private:
			void GetCharacterInput(SDL_Event* e);
			std::string historyContent;
			Text* inputText;
			SDLContext* context;
			BoundingBox* borderBounds;
			SDL_Color bordercolor;
	};
}
#endif
