#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include "SDLGameOverScreen.h"
#include "FileWriter.h"
namespace Game_SDL {

	SDLGameOverScreen::SDLGameOverScreen(SDLContext* context, AbstractFactory* factory, std::string username, int score, Window* window) :
			Screen(factory, window) {
		blinker = -1;
		std::string scorestring = "Score  " + std::to_string(score);

		buttons.push_back(new SDLButton(context, factory, "Menu", 30, 150));
		buttons.push_back(new SDLButton(context, factory, "Quit", 110, 150));
		background = factory->CreateBackground();
		you = factory->CreateText("YOU", 40, 60, 24);
		died = factory->CreateText("DIED", 36, 100, 24);
		youDiedTimer = factory->CreateTimer();
		scoreText = factory->CreateText(scorestring, 75, 140);
		scoreText->HorizontalCenterText(0, 200);
		youDiedTimer->Start();
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

	//Updates Screen for button handling
	void SDLGameOverScreen::Update() {
		//Handle events on queue
		if (buttons[0]->HandleEvent(input)) {
			returnValue = Menu;
		}
		if (buttons[1]->HandleEvent(input)) {
			returnValue = QuitGame;
		}
	}

	//First it lets the "YOU DIED" blink, after 5000 ticks it generates the rest of the UI
	//In the score part, it lets your name blink if you're high enough.
	void SDLGameOverScreen::Visualise() {
		window->PrepareRender();
		background->Visualise();
		if (youDiedTimer->GetTicks() < 5000 && (youDiedTimer->GetTicks() / 250) % 2 == 1) {
			you->Visualise();
			died->Visualise();
		}

		if (youDiedTimer->GetTicks() > 5000) {
			you->Visualise();
			died->Visualise();
			scoreText->Visualise();
			for (SDLButton* button : buttons) {
				button->Visualise();
			}
			for (unsigned int i = 0; i < scores.size(); i++) {
				if (i != blinker || (youDiedTimer->GetTicks() / 250) % 2 == 1)
					scores[i]->Visualise();

			}
		}

		window->PresentRender();
	}

	//Generate the scores for displaying
	void SDLGameOverScreen::GenerateScores(AbstractFactory* factory, std::string username, int score) {
		FileWriter writer;
		writer.ReadScore();
		std::vector<std::string> users = writer.GetUsers();
		std::vector<int> scores = writer.GetScores();
		int y = 40;

		for (unsigned int i = 0; i < users.size(); i++) {
			std::string message = users[i] + ": " + std::to_string(scores[i]);
			this->scores.push_back(factory->CreateText(message, 100, y));
			y += 20;
			if (users[i] == username && scores[i] == score)
				blinker = i;
		}
		cout << blinker << endl;

	}
}
