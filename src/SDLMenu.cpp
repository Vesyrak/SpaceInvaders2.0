#include "SDLMenu.h"
SDLMenu::SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window) :Menu(window) {
	frameTimer=factory->createTimer();
	capTimer=factory->createTimer();
	countedFrames=0;
	this->window=window;
	buttons.push_back(new SDLButton(context,"Start", 0,10));
	buttons.push_back(new SDLButton(context,"Settings", 0,40));
	buttons.push_back(new SDLButton(context,"Stop", 0,70));
	background = factory->createBackground();
	returnValue=0;
	frameTimer->start();
}
SDLMenu::~SDLMenu() {
	delete background;
	std::vector<SDLButton*>::iterator j = buttons.begin();
	while (j != buttons.end()) {
		delete(*j);
		buttons.erase(j++);
	}
}
int SDLMenu::Run() {
	while(returnValue==0){
		capTimer->start();
        float avgFPS = countedFrames / ( frameTimer->getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
		Update();
		Visualise();
	     int frameTicks = capTimer->getTicks();
	                if( frameTicks < 1000/60 )
	                {
	                    //Wait remaining time
	                    frameTimer->delay( 1000/60 - frameTicks );
	                }
	}
	return returnValue;

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
