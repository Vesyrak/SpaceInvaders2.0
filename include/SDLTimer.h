#ifndef SDLTIMER_H
#define SDLTIMER_H
#include "Timer.h"
#include <SDL2/SDL.h>
class SDLTimer: public Timer{
public:
	SDLTimer();
	~SDLTimer();
	void delay(int duration) override;

protected:
	long getLocalTicks() override;

};
#endif
