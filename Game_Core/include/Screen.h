#ifndef SCREEN_H
#define SCREEN_H
#include "Window.h"
#include "Timer.h"
#include "Input.h"
#include "Game.h"

namespace Game_Core {

	class AbstractFactory;

	//Base screen class, everything you see is on some sort of screen
	//Maintains quit conditions & framerate
	class Screen {
		public:
			Screen(AbstractFactory* factory, Window* window);
			virtual ~Screen();
			virtual GameState Run();
		protected:
			virtual void Update()=0;
			virtual void Visualise()=0;
			BaseInput* input;
			GameState returnValue;
			Window* window;
			std::string* alterString;
		private:
			Timer* frameTimer;
			Timer* capTimer;
			Input* inputHandler;
			int countedFrames;
	};
}
#endif
