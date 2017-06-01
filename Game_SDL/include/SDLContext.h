#ifndef SDLCONTEXT_H
#define SDLCONTEXT_H
#include <SDL2/SDL_ttf.h>
#include "SDLWindow.h"
#include "BoundingBox.h"
#include <iostream>
#include <map>
using namespace Game_Core;

namespace Game_SDL {

	//Helper class to help with texture generation and drawing.
	class SDLContext {
		public:
			SDLContext(SDLWindow* window);
			~SDLContext();
			SDL_Texture* GetTexture(std::string path);
			void Draw(SDL_Texture* texture, BoundingBox* bounds);
			SDL_Texture* GenerateText(std::string text, BoundingBox* bounds, int size);
			void DrawRect(SDL_Color* color, BoundingBox* bounds, bool filled);
			void LogicalToActualCoords(BoundingBox* bounds);
			const int defaultFontSize = 14;
		private:
			SDL_Texture* loadTexture(std::string path);
			SDLWindow* window;
			std::map<std::string, SDL_Texture*> textureMap;

	};
}
#endif
