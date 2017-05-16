#ifndef SDLMENU_H
#define SDLMENU_H
#include "SDLButton.h"
#include "AbstractFactory.h"
using namespace Game_Core;

namespace Game_SDL {

	class SDLMenu: public Screen {
		public:
			SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window);
			~SDLMenu();
		protected:
			void Update() override;
			void Visualise() override;
			std::vector<SDLButton*> buttons;
			Background* background;
	};
}
#endif

