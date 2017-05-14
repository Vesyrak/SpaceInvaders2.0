#ifndef SDLSETTINGSSCREEN_H
#define SDLSETTINGSSCREEN_H
#include "AbstractFactory.h"
#include "SDLButton.h"
#include "SDLTextBox.h"
using namespace Game_Core;
namespace Game_SDL{
class SDLSettingsScreen:public Screen{
	public:
		SDLSettingsScreen(AbstractFactory* factory,SDLContext* context, Window* window,std::string* username);
		~SDLSettingsScreen();
	protected:
		void Update() override;
		void Visualise() override;
		SDLButton* backButton;
		Background* background;
		SDLTextBox* textBox;

};
}
#endif
