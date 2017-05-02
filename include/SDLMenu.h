#ifndef SDLMENU_H
#define SDLMENU_H
#include "Menu.h"
#include "SDLButton.h"
#include "AbstractFactory.h"
class SDLMenu : public Menu {
public:
	SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window);
	~SDLMenu();
	int Run() override;
private:
	std::vector<SDLButton*> buttons;
	void Visualise();
	void Update();
	Window* window;
	int returnValue;
	Background* background;
	Timer* frameTimer;
	Timer* capTimer;
	int countedFrames;
};
#endif

