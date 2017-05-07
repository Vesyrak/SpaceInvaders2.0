#include "SDLMenu.h"
SDLMenu::SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window) :Screen(factory, window) {
	buttons.push_back(new SDLButton(factory,context,"Start", 70,60));
	buttons.push_back(new SDLButton(factory,context,"Settings", 70,90));
	buttons.push_back(new SDLButton(factory,context,"Stop", 70,120));
	background = factory->createBackground();

}
SDLMenu::~SDLMenu() {
	delete background;
	buttons.clear();
}

void SDLMenu::Update() {
	background->Update();
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
		}
		for (unsigned int i=0; i<buttons.size(); i++) {
			if(buttons[i]->handleEvent(&e)){
				returnValue=i+1;
			}

		}

	}
}
void SDLMenu::Visualise() {
	window->PrepareRender();
	background->Visualise();
	for(SDLButton* button : buttons){
		button->Visualise();
	}
	window->PresentRender();
}
