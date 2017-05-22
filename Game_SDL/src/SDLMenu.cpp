#include "SDLMenu.h"
namespace Game_SDL {

	SDLMenu::SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window) :
			Screen(factory, window) {
		buttons.push_back(new SDLButton(context, factory, "Start", 70, 60));
		buttons.push_back(new SDLButton(context, factory, "Settings", 70, 90));
		buttons.push_back(new SDLButton(context, factory, "Stop", 70, 120));
		background = factory->CreateBackground();
	}
	SDLMenu::~SDLMenu() {
		delete background;
		for (std::vector<SDLButton*>::iterator it = buttons.begin(); it != buttons.end(); ++it) {
			delete (*it);
		}
		buttons.clear();
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
			window->PresentRender();
		}
	}
