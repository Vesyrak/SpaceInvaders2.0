#ifndef SDLCONTEXT_H
#define SDLCONTEXT_H
#include <SDL2/SDL_ttf.h>
#include "SDLWindow.h"
#include "BoundingBox.h"
#include <iostream>
class SDLContext{
    public:
        SDL_Texture* loadTexture(std::string path);
        SDL_Texture* GenerateText(SDL_Surface* message);
        void Draw(SDL_Texture* texture,BoundingBox* bounds);

        SDLContext(SDLWindow* window);
        ~SDLContext();
    private:
        SDLWindow* window;


};
#endif
