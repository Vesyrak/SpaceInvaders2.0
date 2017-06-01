#ifndef INPUT_H
#define INPUT_H
#include <vector>
#include <string>
#include "BaseInput.h"

namespace Game_Core {

	//Abstract base Input class to be used as template
	class Input {
		public:
			virtual ~Input() {}
			virtual BaseInput* GetInput()=0;
			//Used for text manipulation, e.g. textboxes
			virtual BaseInput* GetInput(std::string* string)=0;
	};
}
#endif
