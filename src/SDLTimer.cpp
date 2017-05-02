#include "SDLTimer.h"
SDLTimer::SDLTimer(){

}
SDLTimer::~SDLTimer(){

}
long SDLTimer::getLocalTicks(){
	return SDL_GetTicks();
}
void SDLTimer::delay(int duration){
	SDL_Delay(duration);
}
