#ifndef SDLBOMBER_H
#define SDLBOMBER_H
#include "Bomber.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL Bomber implementation
	class SDLBomber: public Bomber {
		public:
			SDLBomber(SDLContext* context,AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~SDLBomber();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
			SDL_Texture* chargeImage;
			BoundingBox* chargeBounds;
	};
}
#endif
