#ifndef SDLNEXTLEVELSCREEN_H
#define SDLNEXTLEVELSCREEN_H
#include "AbstractFactory.h"

using namespace Game_Core;

namespace Game_SDL {

	//Next level screen, showing the difficulty
	class SDLNextLevelScreen: public Screen {
		public:
			SDLNextLevelScreen(AbstractFactory* factory, int difficulty, Window* window);
			~SDLNextLevelScreen();

		protected:
			void Update() override;
			void Visualise() override;
			Background* background;
			Text* difficulty;
			Text* number;
			Timer* flashTimer;
	};
}
#endif

