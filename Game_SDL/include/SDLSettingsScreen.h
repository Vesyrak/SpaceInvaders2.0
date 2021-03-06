#ifndef SDLSETTINGSSCREEN_H
#define SDLSETTINGSSCREEN_H
#include "AbstractFactory.h"
#include "SDLButton.h"
#include "SDLTextBox.h"
using namespace Game_Core;

namespace Game_SDL {

	//Screen showing the settings, here only the name editing.
	class SDLSettingsScreen: public Screen {
		public:
			SDLSettingsScreen( SDLContext* context,AbstractFactory* factory, Window* window, std::string* username);
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
