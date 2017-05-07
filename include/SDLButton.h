#ifndef SDLBUTTON_H
#define SDLBUTTON_H
#include "AbstractFactory.h"
#include "SDLContext.h"
#include "Text.h"
//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

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
        //Initializes internal variables
        SDLButton(AbstractFactory* factory,SDLContext* context,std::string text, int x, int y);
        ~SDLButton();

        //Handles mouse event
        int handleEvent( SDL_Event* e );
        //Shows button sprite
        void Visualise();
        int Update();
    private:
        void CenterText();
        //Top left position
        Text* text;
        SDLContext* context;
        //Currently used global sprite
        ButtonState mCurrentSprite;
        BoundingBox* borderBounds;
        BoundingBox* buttonBounds;
        BoundingBox* actualButtonBounds;
        SDL_Color buttonColors[6];

};
#endif
