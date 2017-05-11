#ifndef SDLMENU_H
#define SDLMENU_H
#include "SDLButton.h"
#include "AbstractFactory.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLMenu : public Screen {
public:
	SDLMenu(SDLContext* context, AbstractFactory* factory, Window* window);
	~SDLMenu();
protected:
	std::vector<SDLButton*> buttons;
	void Visualise() override;
	void Update()override;
	Background* background;
};}
#endif

