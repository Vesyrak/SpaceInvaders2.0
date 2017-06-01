#include "BaseInput.h"

namespace Game_Core {

	//Constructor sets required parameters
	BaseInput::BaseInput() {
		mouseX = mouseY = -1;
		mousepress=false;
	}

	BaseInput::~BaseInput() {
	}
}
