#ifndef INPUT_H
#define INPUT_H
#include <vector>
namespace Game_Core {

	enum InputType {
		None, Left, Right, Up, Down, A, B, X, Y
	};
	class Input {
		public:
			virtual ~Input() {
			}
			virtual std::vector<InputType> GetInput()=0;
	};
}
#endif
