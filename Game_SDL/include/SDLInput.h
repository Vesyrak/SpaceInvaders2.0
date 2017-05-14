#ifndef SDLINPUT_H
#define SDLINPUT_H
#include "Input.h"
using namespace Game_Core;

namespace Game_SDL {

class SDLInput: public Input{
    public:
        SDLInput();
        std::vector<InputType> getInput();
        ~SDLInput();

};}
#endif
