#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include "SDLGameOverScreen.h"
#include "FileWriter.h"
namespace Game_SDL {

SDLGameOverScreen::SDLGameOverScreen(std::string username, int score, SDLContext* context, AbstractFactory* factory, Window* window) :
		Screen(factory, window) {
	buttons.push_back(new SDLButton(factory, context, "Menu", 30, 150));
	buttons.push_back(new SDLButton(factory, context, "Quit", 110, 150));
	background = factory->createBackground();
	you = factory->createText("YOU", 40, 60, 24);
	died = factory->createText("DIED", 36, 100, 24);
	returnValue = 0;
	youDiedTimer = factory->createTimer();
	youDiedTimer->start();
	std::string scorestring = "Score  " + std::to_string(score);
	scoreText = factory->createText(scorestring, 75, 140);
	blinker = -1;
	GenerateScores(factory, username, score);
}
SDLGameOverScreen::~SDLGameOverScreen() {
	delete you;
	delete died;
	delete scoreText;
	delete youDiedTimer;
	delete background;
	for (std::vector<SDLButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
		delete (*it);
	}
	buttons.clear();
	for (std::vector<Text*>::iterator it = scores.begin(); it != scores.end(); ++it) {
		delete (*it);
	}
	scores.clear();
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
	if (youDiedTimer->getTicks() < 5000 && (youDiedTimer->getTicks() / 250) % 2 == 1) {
		you->Visualise();
		died->Visualise();
	}

	if (youDiedTimer->getTicks() > 5000) {
		you->Visualise();
		died->Visualise();
		scoreText->Visualise();
		for (SDLButton* button : buttons) {
			button->Visualise();
		}
		for ( int i = 0; i < scores.size(); i++) {
			if (i != blinker || (youDiedTimer->getTicks() / 250) % 2 == 1)
				scores[i]->Visualise();

		}
	}

	window->PresentRender();
}
void SDLGameOverScreen::GenerateScores(AbstractFactory* factory, std::string username, int score) {
	FileWriter writer;
	writer.readScore();
	std::vector<std::string> users = writer.getUsers();
	std::vector<int> scores = writer.getScores();
	int y = 40;

	for (unsigned int i = 0; i < users.size(); i++) {
		std::string message = users[i] + ": " + std::to_string(scores[i]);
		this->scores.push_back(factory->createText(message, 100, y));
		y += 20;
		if (users[i] == username && scores[i] == score)
			blinker = i;
	}
	cout << blinker << endl;

}
}
