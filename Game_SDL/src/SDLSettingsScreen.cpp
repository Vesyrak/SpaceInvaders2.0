#include "SDLSettingsScreen.h"
namespace Game_SDL {
	SDLSettingsScreen::SDLSettingsScreen(SDLContext* context, AbstractFactory* factory, Window* window, std::string* username) :
			Screen(factory, window) {
		background = factory->CreateBackground();
		textBox = new SDLTextBox(context,factory, username, 70, 75);
		backButton = new SDLButton(context, factory, "Back", 70, 105);
		alterString=textBox->content;
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

			textBox->HandleEvent(input);
			if (backButton->HandleEvent(input)) {
				returnValue = 1;


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
