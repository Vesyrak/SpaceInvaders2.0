#include <algorithm>
#include "Screen.h"
#include "AbstractFactory.h"
namespace Game_Core {

	Screen::Screen(AbstractFactory* factory, Window* window) {
		this->window = window;
		countedFrames = returnValue = -1;
		frameTimer = factory->CreateTimer();
		capTimer = factory->CreateTimer();
		inputHandler = factory->GetInputHandler();
		frameTimer->Start();
		alterString = NULL;
		input = NULL;
	}

	Screen::~Screen() {
		delete frameTimer;
		delete capTimer;

	}

	//Maintains FPS for all screens
	int Screen::Run() {
		while (returnValue == -1) {
			if (alterString != NULL)
				input = inputHandler->GetInput(alterString);
			else
				input = inputHandler->GetInput();

			if (std::find(input->inputVector.begin(), input->inputVector.end(), InputType::Quit) != input->inputVector.end())
				returnValue = 0;
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
