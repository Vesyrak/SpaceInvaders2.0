#ifndef INPUT_H
#define INPUT_H
#include <vector>
enum InputType{None, Left, Right, Up, Down, A, B, X, Y };
class Input{
    public:
        virtual std::vector<InputType> getInput()=0;

};
#endif
