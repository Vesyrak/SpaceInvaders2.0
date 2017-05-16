#ifndef SCREEN_H
#define SCREEN_H
#include "Window.h"
#include "Timer.h"
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
			Timer* frameTimer;
			Timer* capTimer;
			Window* window;
			int returnValue;
			int countedFrames;
	};
}
#endif
