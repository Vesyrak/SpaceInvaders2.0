#ifndef SDLLIFEPOWERUP_H
#define SDLLIFEPOWERUP_H
#include "LifePowerUp.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the LifePowerUp
	class SDLLifePowerUp: public LifePowerUp {
		public:
			SDLLifePowerUp(SDLContext* context, PlayerShip* playerShip, int x, int y);
			~SDLLifePowerUp();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
	};
}
#endif
