#ifndef SDLGAMEOVERSCREEN_H
#define SDLGAMEOVERSCREEN_H
#include "AbstractFactory.h"
#include "SDLButton.h"
#include "Screen.h"
#include "SDLContext.h"
class SDLGameOverScreen: public Screen {
public:
	SDLGameOverScreen(int score,SDLContext* context,AbstractFactory* factory,Window* window);
	~SDLGameOverScreen();
protected:
	void Update() override;
	void Visualise() override;
	std::vector<SDLButton*> buttons;
	Background* background;
	Text* you;
	Text* died;
	Text* scoreText;
	Timer* youDiedTimer;
};
#endif

