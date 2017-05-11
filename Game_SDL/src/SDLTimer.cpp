#include "SDLTimer.h"
namespace Game_SDL {

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
}
