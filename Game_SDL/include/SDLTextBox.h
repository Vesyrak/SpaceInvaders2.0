#ifndef SDLTEXTBOX_H
#define SDLTEXTBOX_H
#include "Text.h"
#include "AbstractFactory.h"
#include "SDLContext.h"
using namespace Game_Core;
namespace Game_SDL{
class SDLTextBox{
	public:
		SDLTextBox(AbstractFactory* factory,SDLContext* context, int x, int y);
		~SDLTextBox();
        void Visualise();
void Update();
	private:
        std::string username;
        Text* inputText;
        SDLContext* context;
        BoundingBox* borderBounds;
        Input* input;
        SDL_Color bordercolor;
};
}
#endif
