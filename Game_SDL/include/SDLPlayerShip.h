#ifndef SDLPLAYERSHIP_H
#define SDLPLAYERSHIP_H
#include "PlayerShip.h"
#include "SDLContext.h"
using namespace std;
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the playership
	class SDLPlayerShip: public PlayerShip {
		public:
			SDLPlayerShip(SDLContext* context, AbstractFactory* factory, std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed);
			~SDLPlayerShip();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;

	};
}
#endif

