#ifndef SDLLASER_H
#define SDLLASER_H
#include "Laser.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the Laser
	class SDLLaser: public Laser {
		public:
			SDLLaser(SDLContext* context, double x, double y, int movementSpeed, InputType direction, int damage);
			~SDLLaser();
			void Visualise() override;
		private:
			SDL_Texture* image;
			SDLContext* context;
	};
}
#endif
