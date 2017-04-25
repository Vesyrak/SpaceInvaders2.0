#include "SDLAudioEngine.h"
#include <iostream>

SDLAudioEngine::SDLAudioEngine(){
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return;
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return;
    }
    Mix_Chunk* music= Mix_LoadWAV( "audio/test.wav" );
    if( music == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    Mix_PlayChannel( -1, music, 0 );

}

SDLAudioEngine::~SDLAudioEngine(){
    Mix_Quit();
}

void SDLAudioEngine::PlaySound(EntityType sound){
    switch(sound){
        case BasherAttack:
            break;
        case BlasterAttack:
            break;
        case BomberAttack:
            break;
        case BossAttack:
            break;
        case PlayerShipAttack:
            break;
        case Damaged:
            break;
        case Death:
            break;
    }
}
void SDLAudioEngine::PlayBackground(){
}
