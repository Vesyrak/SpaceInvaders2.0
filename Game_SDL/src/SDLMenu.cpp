#include "SDLMenu.h"
namespace Game_SDL {

	SDLMenu::SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window) :
			Screen(factory, window) {
		header = factory->CreateText("Space Invaders", 20, 20, 30);
		header->HorizontalCenterText(0, 200);
		version = factory->CreateText("2.0", 20, 40, 30);
		version->HorizontalCenterText(0, 200);
		buttons.push_back(new SDLButton(context, factory, "Start", 70, 80));
		buttons.push_back(new SDLButton(context, factory, "Settings", 70, 110));
		buttons.push_back(new SDLButton(context, factory, "Stop", 70, 140));
		background = factory->CreateBackground();
	}
	SDLMenu::~SDLMenu() {
		delete header;
		delete version;
		for (std::vector<SDLButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
			delete (*it);
		}
		buttons.clear();
		delete background;

	}

	//Updates Buttons
	void SDLMenu::Update() {
		background->Update();

		for (unsigned int i = 0; i < buttons.size(); i++) {
			if (buttons[i]->HandleEvent(input)) {
				returnValue = i + 1;
			}
		}
	}

	void SDLMenu::Visualise() {
		window->PrepareRender();
		background->Visualise();
		for (SDLButton* button : buttons) {
			button->Visualise();
		}
		header->Visualise();
		version->Visualise();
		window->PresentRender();
	}
}
