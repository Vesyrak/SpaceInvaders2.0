#ifndef SCREEN_H
#define SCREEN_H
#include "Window.h"
#include "Timer.h"
#include "Input.h"
namespace Game_Core {

	class AbstractFactory;
	class Screen {
		public:
			Screen(AbstractFactory* factory, Window* window);
			virtual ~Screen();
			virtual int Run();
		protected:
			virtual void Update()=0;
			virtual void Visualise()=0;
			BaseInput* input;
			int returnValue;
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
