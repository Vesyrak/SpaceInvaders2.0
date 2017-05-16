#include "Screen.h"
#include "AbstractFactory.h"
namespace Game_Core {

Screen::Screen(AbstractFactory* factory, Window* window) {
	this->window = window;
	countedFrames=returnValue = 0;
	frameTimer = factory->CreateTimer();
	capTimer = factory->CreateTimer();
	frameTimer->Start();

}
Screen::~Screen() {
	delete frameTimer;
	delete capTimer;

}
int Screen::Run() {
	while (returnValue == 0) {
		capTimer->Start();
		float avgFPS = countedFrames / (frameTimer->GetTicks() / 1000.f);
		if (avgFPS > 2000000) {
			avgFPS = 0;
		}
		Update();
		Visualise();
		int frameTicks = capTimer->GetTicks();
		if (frameTicks < 1000 / 60) {
			//Wait remaining time
			frameTimer->Delay(1000 / 60 - frameTicks);
		}
	}
	return returnValue;
}
}
