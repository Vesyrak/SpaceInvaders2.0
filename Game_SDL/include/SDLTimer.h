#ifndef SDLTIMER_H
#define SDLTIMER_H
#include "Timer.h"
#include <SDL2/SDL.h>
using namespace Game_Core;

namespace Game_SDL {

	//SDL Implementation of the timer
	class SDLTimer: public Timer {
		public:
			SDLTimer();
			~SDLTimer();
			void Delay(int duration) override;
		protected:
			long GetLocalTicks() override;

	};
}
#endif
