#include "SDLSettingsScreen.h"
namespace Game_SDL {
	SDLSettingsScreen::SDLSettingsScreen(SDLContext* context, AbstractFactory* factory, Window* window, std::string* username) :
			Screen(factory, window) {
		background = factory->CreateBackground();
		textBox = new SDLTextBox(context,factory, username, 70, 75);
		backButton = new SDLButton(context, factory, "Back", 70, 105);
		SDL_StartTextInput();

	}
	SDLSettingsScreen::~SDLSettingsScreen() {
		delete background;
		delete textBox;
		delete backButton;
		SDL_StopTextInput();

	}

	//Updates background & buttons
	void SDLSettingsScreen::Update() {
		background->Update();
		SDL_Event e;
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
			}
			textBox->HandleEvent(&e);
			if (backButton->HandleEvent(&e)) {
				returnValue = 1;
			}

		}
	}
	void SDLSettingsScreen::Visualise() {
		window->PrepareRender();
		background->Visualise();
		textBox->Visualise();
		backButton->Visualise();
		window->PresentRender();
	}
}
