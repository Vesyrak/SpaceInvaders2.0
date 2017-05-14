#include "SDLNextLevelScreen.h"
namespace Game_SDL {
SDLNextLevelScreen::SDLNextLevelScreen(int difficulty,AbstractFactory* factory,Window* window):Screen(factory, window){
	this->difficulty=factory->createText("Difficulty:",40,70,30);
	this->difficulty->HorizontalCenterText(0,200);
	number=factory->createText(std::to_string(difficulty), 90,110,30);
	number->HorizontalCenterText(0,200);
	background=factory->createBackground();
	flashTimer=factory->createTimer();
	flashTimer->start();
}
SDLNextLevelScreen::~SDLNextLevelScreen(){
	delete difficulty;
	delete number;
	delete background;
	delete flashTimer;
}
void SDLNextLevelScreen::Update(){
	background->Update();
	if (flashTimer->getTicks() >2500) {
		returnValue=1;
	}
}
void SDLNextLevelScreen::Visualise(){
	window->PrepareRender();
	background->Visualise();
	difficulty->Visualise();
	if (flashTimer->getTicks()>1500||(flashTimer->getTicks() / 250) % 2 == 1) {
		number->Visualise();
	}
	window->PresentRender();
}
}
