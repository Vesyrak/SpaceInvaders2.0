#include "SDLMenu.h"
SDLMenu::SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window) :Screen(factory, window) {
	buttons.push_back(new SDLButton(context,"Start", 0,10));
	buttons.push_back(new SDLButton(context,"Settings", 0,40));
	buttons.push_back(new SDLButton(context,"Stop", 0,70));
	background = factory->createBackground();

}
SDLMenu::~SDLMenu() {
	delete background;
	std::vector<SDLButton*>::iterator j = buttons.begin();
	while (j != buttons.end()) {
		delete(*j);
		buttons.erase(j++);
	}
}

void SDLMenu::Update() {
	background->Update();
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
		}
		for (int i=0; i<buttons.size(); i++) {
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
