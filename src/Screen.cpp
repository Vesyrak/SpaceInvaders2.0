#include "Screen.h"
#include "AbstractFactory.h"
Screen::Screen(AbstractFactory* factory, Window* window) {
	this->window = window;
	countedFrames=returnValue = 0;
	frameTimer = factory->createTimer();
	capTimer = factory->createTimer();
	frameTimer->start();

}
Screen::~Screen() {
	delete frameTimer;
	delete capTimer;

}
int Screen::Run() {
	while (returnValue == 0) {
		capTimer->start();
		float avgFPS = countedFrames / (frameTimer->getTicks() / 1000.f);
		if (avgFPS > 2000000) {
			avgFPS = 0;
		}
		Update();
		Visualise();
		int frameTicks = capTimer->getTicks();
		if (frameTicks < 1000 / 60) {
			//Wait remaining time
			frameTimer->delay(1000 / 60 - frameTicks);
		}
	}
	return returnValue;
}
