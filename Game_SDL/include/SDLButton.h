#ifndef SDLBUTTON_H
#define SDLBUTTON_H
#include "AbstractFactory.h"
#include "SDLContext.h"
#include "Text.h"
using namespace Game_Core;
namespace Game_SDL {
enum ButtonState
{
	BUTTON_MOUSE_OUT = 0,
    BUTTON_MOUSE_OVER_MOTION = 1,
    BUTTON_MOUSE_DOWN = 2,
    BUTTON_MOUSE_UP = 3,
    BUTTON_TOTAL = 4
};

class SDLButton
{
    public:
        SDLButton(AbstractFactory* factory,SDLContext* context,std::string text, int x, int y);
        ~SDLButton();

        int handleEvent( SDL_Event* e );
        void Visualise();
    private:
        void CenterText();
        Text* text;
        SDLContext* context;
        ButtonState mCurrentSprite;
        BoundingBox* borderBounds;
        BoundingBox* buttonBounds;
        BoundingBox* actualButtonBounds;
        SDL_Color buttonColors[6];

};}
#endif
