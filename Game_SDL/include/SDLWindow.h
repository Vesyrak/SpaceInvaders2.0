#ifndef SDLWINDOW_H
#define SDLWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Window.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the Window
	class SDLWindow: public Window {
		public:
			SDL_Renderer* renderer;
			SDL_Window* window;
			SDLWindow();
			SDLWindow(int screen_width, int screen_height);
			~SDLWindow();
			int CreateWindow();
			void PrepareRender();
			void PresentRender();

	};
}
#endif

