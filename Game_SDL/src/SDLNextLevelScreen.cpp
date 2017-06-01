#define __USE_MINGW_ANSI_STDIO 0
#include "SDLNextLevelScreen.h"

namespace Game_SDL {

	SDLNextLevelScreen::SDLNextLevelScreen(AbstractFactory* factory, int difficulty, Window* window) :Screen(factory, window) {
		this->difficulty = factory->CreateText("Difficulty:", 40, 70, 30);
		this->difficulty->HorizontalCenterText(0, 200);
		number = factory->CreateText(std::to_string(difficulty), 90, 110, 30);
		number->HorizontalCenterText(0, 200);
		background = factory->CreateBackground();
		flashTimer = factory->CreateTimer();
		flashTimer->Start();
	}

	SDLNextLevelScreen::~SDLNextLevelScreen() {
		delete difficulty;
		delete number;
		delete background;
		delete flashTimer;
	}

	//Updates bg and flashes difficulty
	void SDLNextLevelScreen::Update() {
		background->Update();
		if (flashTimer->GetTicks() > 2500) {
			returnValue = Running;
		}
	}

	void SDLNextLevelScreen::Visualise() {
		window->PrepareRender();
		background->Visualise();
		difficulty->Visualise();
		if (flashTimer->GetTicks() > 1500 || (flashTimer->GetTicks() / 250) % 2 == 1) {
			number->Visualise();
		}
		window->PresentRender();
	}
}
