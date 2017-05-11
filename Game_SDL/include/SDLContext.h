#ifndef SDLCONTEXT_H
#define SDLCONTEXT_H
#include <SDL2/SDL_ttf.h>
#include "SDLWindow.h"
#include "BoundingBox.h"
#include <iostream>
#include <map>
using namespace Game_Core;

namespace Game_SDL {

class SDLContext {
public:
	SDL_Texture* getTexture(std::string path);
	void Draw(SDL_Texture* texture, BoundingBox* bounds);
	SDL_Texture* GenerateText(std::string text, BoundingBox* bounds,int size);
	void DrawRect(SDL_Color* color, BoundingBox* bounds, bool filled);
	SDLContext(SDLWindow* window);
	~SDLContext();
	void LogicalToActualCoords(BoundingBox* bounds);
	const int defaultFontSize=14;
private:
	SDL_Texture* loadTexture(std::string path);
	SDLWindow* window;
	std::map<std::string, SDL_Texture*> textureMap;

};}
#endif
