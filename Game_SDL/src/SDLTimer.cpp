#include "SDLTimer.h"
namespace Game_SDL {

	SDLTimer::SDLTimer() {

	}

	SDLTimer::~SDLTimer() {

	}

	long SDLTimer::GetLocalTicks() {
		return SDL_GetTicks();
	}

	void SDLTimer::Delay(int duration) {
		SDL_Delay(duration);
	}
}
