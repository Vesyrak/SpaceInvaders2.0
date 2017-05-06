#ifndef SDLCONTEXT_H
#define SDLCONTEXT_H
#include <SDL2/SDL_ttf.h>
#include "SDLWindow.h"
#include "BoundingBox.h"
#include <iostream>
class SDLContext {
public:
	SDL_Texture* loadTexture(std::string path);
	void Draw(SDL_Texture* texture, BoundingBox* bounds);
	SDL_Texture* GenerateText(std::string text, BoundingBox* bounds);
	void DrawRect(SDL_Color* color, BoundingBox* bounds, bool filled);
	void InitializeFont();
	SDLContext(SDLWindow* window);
	~SDLContext();
	void LogicalToActualCoords(BoundingBox* bounds);
private:
	SDLWindow* window;
	TTF_Font* font;

};
#endif
