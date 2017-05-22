#ifndef INPUT_H
#define INPUT_H
#include <vector>
#include <string>
#include "BaseInput.h"
namespace Game_Core {

	class Input {
		public:
			virtual ~Input() {}
			virtual BaseInput* GetInput()=0;
			virtual BaseInput* GetInput(std::string* string)=0;
	};
}
#endif
