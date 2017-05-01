#ifndef MENU_H
#define MENU_H
#include "Window.h"
class Menu {
public:
	Menu(Window* window);
	~Menu();
	virtual int Run()=0;
protected:
	Window* window;
};
#endif

