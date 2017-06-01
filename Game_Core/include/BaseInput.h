#ifndef BASEINPUT_H
#define BASEINPUT_H
#include <vector>

namespace Game_Core {

	//Enum of Input types: Set to Standard XBOX controller layout
	enum InputType {
		None, Left, Right, Up, Down, A, B, X, Y, Quit
	};

	//Object containing all the information about input the game needs
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
