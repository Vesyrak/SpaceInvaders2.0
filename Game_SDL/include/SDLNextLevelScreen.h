#ifndef SDLNEXTLEVELSCREEN_H
#define SDLNEXTLEVELSCREEN_H
#include "AbstractFactory.h"

using namespace Game_Core;

namespace Game_SDL {

class SDLNextLevelScreen: public Screen {
    public:
		SDLNextLevelScreen(int difficulty,AbstractFactory* factory,Window* window);
        ~SDLNextLevelScreen();

    protected:
        void Update() override;
        void Visualise() override;
    	Background* background;
    	Text* difficulty;
    	Text* number;
    	Timer* flashTimer;
};}
#endif

