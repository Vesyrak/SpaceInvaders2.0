#ifndef SDLBLASTER_H
#define SDLBLASTER_H
#include "Blaster.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL Blaster implementation
	class SDLBlaster: public Blaster {
		public:
			SDLBlaster(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~SDLBlaster();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
	};
}

#endif
