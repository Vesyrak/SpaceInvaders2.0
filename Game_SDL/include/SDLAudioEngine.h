#ifndef SDLAUDIOENGINE_H
#define SDLAUDIOENGINE_H
#include "AudioEngine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
using namespace Game_Core;
namespace Game_SDL {
class SDLAudioEngine: public AudioEngine{
public:
	SDLAudioEngine();
	~SDLAudioEngine();
    void PlaySound(SoundType sound) override;
    void PlayBackground();
private:
    Mix_Music* backgroundSound;
    Mix_Chunk* shootSound;
    Mix_Chunk* damagedSound;
    Mix_Chunk* deathSound;

};}
#endif
