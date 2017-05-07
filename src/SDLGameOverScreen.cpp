#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include "SDLGameOverScreen.h"
SDLGameOverScreen::SDLGameOverScreen(int score, SDLContext* context,AbstractFactory* factory, Window* window) :Screen(factory, window){
	buttons.push_back(new SDLButton(factory, context, "Continue", 30, 150));
	buttons.push_back(new SDLButton(factory,context, "Save+Quit", 110, 150));
	background = factory->createBackground();
	you = factory->createText("YOU", 80, 60,24);
	died = factory->createText("DIED", 80, 100,24);
	returnValue = 0;
	youDiedTimer = factory->createTimer();
	youDiedTimer->start();
	std::string scorestring="Score  "+std::to_string(score);
	scoreText=factory->createText(scorestring,75, 140);
}
SDLGameOverScreen::~SDLGameOverScreen() {
	delete you;
	delete died;
	delete scoreText;
	delete youDiedTimer;
	delete background;
	std::vector<SDLButton*>::iterator j = buttons.begin();
	while (j < buttons.end()) {
		delete (*j++);
	}
}

void SDLGameOverScreen::Update() {
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
		}
		for (unsigned int i = 0; i < buttons.size(); i++) {
			if (buttons[i]->handleEvent(&e)) {
				returnValue = i + 1;
			}

		}

	}
}
void SDLGameOverScreen::Visualise() {
	window->PrepareRender();
	background->Visualise();
	if(youDiedTimer->getTicks()<5000&& (youDiedTimer->getTicks() / 250) % 2 == 1)
	{
		you->Visualise();
		died->Visualise();
	}

	if(youDiedTimer->getTicks()>5000)
	{
		you->Visualise();
		died->Visualise();
		scoreText->Visualise();
		for (SDLButton* button : buttons) {
			button->Visualise();
		}
	}
	window->PresentRender();
}
