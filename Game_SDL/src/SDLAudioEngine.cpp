#include "SDLAudioEngine.h"
#include <iostream>
namespace Game_SDL {

	//Initializes SDL Audio and loads music
	SDLAudioEngine::SDLAudioEngine() {
		if (SDL_Init( SDL_INIT_AUDIO) < 0) {
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			return;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
			return;
		}
		backgroundSound = Mix_LoadMUS("audio/test.wav");
		shootSound = Mix_LoadWAV("audio/pew.wav");
		damagedSound = Mix_LoadWAV("audio/explosion.wav");
		deathSound = Mix_LoadWAV("audio/wilhelm.wav");
	}

	SDLAudioEngine::~SDLAudioEngine() {
		Mix_FreeMusic(backgroundSound);
		Mix_FreeChunk(shootSound);
		Mix_FreeChunk(damagedSound);
		Mix_FreeChunk(deathSound);
		Mix_Quit();
	}

	//Play a sound effect
	void SDLAudioEngine::PlaySound(SoundType sound) {
		switch (sound) {
			case Shoot:
				Mix_PlayChannel(-1, shootSound, 0);
				break;
			case Damaged:
				Mix_PlayChannel(-1, damagedSound, 0);
				break;
			case Death:
				Mix_PlayChannel(-1, deathSound, 0);
				break;
		}
	}

	// Play background music
	void SDLAudioEngine::PlayBackground() {
		Mix_PlayMusic(backgroundSound, -1);
	}
}
