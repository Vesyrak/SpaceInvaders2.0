#ifndef SCREEN_H
#define SCREEN_H
#include "Window.h"
#include "Timer.h"
class AbstractFactory;
class Screen {
public:
	Screen(AbstractFactory* factory, Window* window);
	virtual ~Screen();
	virtual int Run();
protected:
	virtual void Update()=0;
	virtual void Visualise()=0;
	Window* window;
	int returnValue;
	Timer* frameTimer;
	Timer* capTimer;
	int countedFrames;
};
#endif
