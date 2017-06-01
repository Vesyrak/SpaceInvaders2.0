#ifndef SDLBASHER_H
#define SDLBASHER_H
#include "Basher.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL Basher implementation
	class SDLBasher: public Basher {
		public:
			SDLBasher(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~SDLBasher();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
	};
}
#endif
