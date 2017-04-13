#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Window.h"

class SDLWindow: public Window{
    public:
        SDL_Surface* Surface_Display;
        SDL_Renderer* renderer;
        SDL_Window* window;
    private:
        SDL_Texture* background;

    public:
        SDLWindow();
        SDLWindow( int screen_width, int screen_height);
        ~SDLWindow();
        int CreateWindow();
        void PrepareRender();
        void PresentRender();

};
#endif

