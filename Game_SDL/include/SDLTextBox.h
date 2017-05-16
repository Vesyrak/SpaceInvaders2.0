#ifndef SDLTEXTBOX_H
#define SDLTEXTBOX_H
#include "Text.h"
#include "AbstractFactory.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL {
	class SDLTextBox {
		public:
			SDLTextBox(SDLContext* context, AbstractFactory* factory, std::string* text, int x, int y);
			~SDLTextBox();
			void Visualise();
			void HandleEvent(SDL_Event* e);

		private:
			void GetCharacterInput(SDL_Event* e);
			std::string* content;
			std::string historyContent;
			Text* inputText;
			SDLContext* context;
			BoundingBox* borderBounds;
			SDL_Color bordercolor;
	};
}
#endif
