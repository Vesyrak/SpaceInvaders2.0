#ifndef SDLHEALTHBAR_H
#define SDLHEALTHBAR_H
#include "Healthbar.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the healthbar
	class SDLHealthbar: public Healthbar {
		public:
			SDLHealthbar(SDLContext* context, AbstractFactory* factory, Entity* observed, int x, int y);
			~SDLHealthbar();
			void Update() override;
			void Visualise() override;
		private:
			SDLContext* context;
			SDL_Color backColor;
			SDL_Color frontColor;
			int starthp;
			int prevhp;
	};
}
#endif
