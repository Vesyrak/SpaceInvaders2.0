#ifndef SDLINPUT_H
#define SDLINPUT_H
#include "Input.h"
#include "BaseInput.h"
using namespace Game_Core;

namespace Game_SDL {

	//SDL implementation of the input handler
	class SDLInput: public Input {
		public:
			SDLInput();
			~SDLInput();
			BaseInput* GetInput() override;
			BaseInput* GetInput(std::string* string) override;

	};
}
#endif
