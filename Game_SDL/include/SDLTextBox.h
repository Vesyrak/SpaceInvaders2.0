#ifndef SDLTEXTBOX_H
#define SDLTEXTBOX_H
#include "Text.h"
#include "AbstractFactory.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL{
class SDLTextBox{
	public:
		SDLTextBox(AbstractFactory* factory,SDLContext* context, std::string* text,int x, int y);
		~SDLTextBox();
        void Visualise();
        void handleEvent(SDL_Event* e);

	private:
        void getCharacterInput(SDL_Event* e);
        std::string* content;
        std::string historyContent;
        Text* inputText;
        SDLContext* context;
        BoundingBox* borderBounds;
        SDL_Color bordercolor;
};
}
#endif
