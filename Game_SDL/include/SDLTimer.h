#ifndef SDLTIMER_H
#define SDLTIMER_H
#include "Timer.h"
#include <SDL2/SDL.h>
using namespace Game_Core;

namespace Game_SDL {

class SDLTimer: public Timer{
public:
	SDLTimer();
	~SDLTimer();
	void delay(int duration) override;

protected:
	long getLocalTicks() override;

};}
#endif