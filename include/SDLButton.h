#ifndef SDLBUTTON_H
#define SDLBUTTON_H
#include "AbstractFactory.h"
#include "SDLContext.h"
//Button constants
const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum SDLButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class SDLButton
{
    public:
        //Initializes internal variables
        SDLButton(SDLContext* context,std::string text, int x, int y);
        ~SDLButton();
        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        int handleEvent( SDL_Event* e );
        //Shows button sprite
        void Visualise();
        int Update();

    private:
        //Top left position
        SDL_Texture* images[5];
        SDL_Texture* text;
        SDLContext* context;
        //Currently used global sprite
        SDLButtonSprite mCurrentSprite;
        BoundingBox* buttonBounds;
        BoundingBox* textBounds;
        BoundingBox* actualButtonBounds;
};
#endif
