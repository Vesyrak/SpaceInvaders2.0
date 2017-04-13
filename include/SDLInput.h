#ifndef SDLINPUT_H
#define SDLINPUT_H
#include "Input.h"
class SDLInput: public Input{
    private:
        SDL_Event event;
    public:
        SDLInput();
        std::vector<InputType> getInput();

};
#endif
