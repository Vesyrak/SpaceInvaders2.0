#ifndef SDLGAMEOVERSCREEN_H
#define SDLGAMEOVERSCREEN_H
#include "AbstractFactory.h"
#include "SDLButton.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

	class SDLGameOverScreen: public Screen {
		public:
			SDLGameOverScreen(SDLContext* context, AbstractFactory* factory,std::string username, int score, Window* window);
			~SDLGameOverScreen();
		protected:
			void Update() override;
			void Visualise() override;
			void GenerateScores(AbstractFactory* factory, std::string username, int score);
			std::vector<SDLButton*> buttons;
			std::vector<Text*> scores;
			Background* background;
			Text* you;
			Text* died;
			Text* scoreText;
			Timer* youDiedTimer;
			int blinker;
	};
}
#endif

