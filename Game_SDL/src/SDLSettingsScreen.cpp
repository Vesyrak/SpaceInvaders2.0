#include "SDLSettingsScreen.h"
namespace Game_SDL {
SDLSettingsScreen::SDLSettingsScreen(AbstractFactory* factory, SDLContext* context, Window* window, std::string* username) :
		Screen(factory, window) {
	background = factory->createBackground();
	textBox = new SDLTextBox(factory, context,username, 70, 75);
	backButton = new SDLButton(factory, context, "Back", 70, 105);
	SDL_StartTextInput();

}
SDLSettingsScreen::~SDLSettingsScreen() {
	delete background;
	delete textBox;
	delete backButton;
	SDL_StopTextInput();

}

void SDLSettingsScreen::Update() {
	background->Update();
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
		}
		textBox->handleEvent(&e);
		if (backButton->handleEvent(&e)) {
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
