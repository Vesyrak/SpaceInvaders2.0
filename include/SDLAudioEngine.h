#ifndef SDLAUDIOENGINE_H
#define SDLAUDIOENGINE_H
#include "AudioEngine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
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

};
#endif
