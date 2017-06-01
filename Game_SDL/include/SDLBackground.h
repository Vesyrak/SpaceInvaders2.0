#ifndef SDLBACKGROUND_H
#define SDLBACKGROUND_H
#include "Background.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL Background implementation
	class SDLBackground: public Background {
		public:
			SDLBackground(SDLContext* context);
			~SDLBackground();
			void Update() override;
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
			int scrollingOffset;
			BoundingBox* scrollBounds;
	};
}
#endif

