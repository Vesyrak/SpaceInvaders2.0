#ifndef BASEINPUT_H
#define BASEINPUT_H
#include <vector>
namespace Game_Core {
	enum InputType {
		None, Left, Right, Up, Down, A, B, X, Y, Quit
	};
    class BaseInput {
    public:
    	BaseInput();
        ~BaseInput();
        std::vector<InputType> inputVector;
        int mouseX;
        int mouseY;
        bool mousepress;
    };
}
#endif
