#ifndef SDLGAMEOVERSCREEN_H
#define SDLGAMEOVERSCREEN_H
#include "AbstractFactory.h"
#include "SDLButton.h"
#include "Screen.h"
#include "SDLContext.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLGameOverScreen: public Screen {
public:
	SDLGameOverScreen(std::string username,int score,SDLContext* context,AbstractFactory* factory,Window* window);
	~SDLGameOverScreen();
protected:
	void GenerateScores(AbstractFactory* factory,std::string username,int score);
	void Update() override;
	void Visualise() override;
	std::vector<SDLButton*> buttons;
	std::vector<Text*> scores;
	Background* background;
	Text* you;
	Text* died;
	Text* scoreText;
	Timer* youDiedTimer;
	int blinker;
};}
#endif

