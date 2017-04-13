#include<stdio.h>
#include "SDLContext.h"
SDLContext::SDLContext(SDLWindow* window){
    this->window=window;
}

void SDLContext::Draw(SDL_Texture* texture, BoundingBox* bounds){
    SDL_Rect DestR;

    DestR.x = window->screen_width / window->logical_width  * bounds->getX();
    DestR.y = window->screen_height / window->logical_height * bounds->getY() ;
    DestR.w = 32;
    DestR.h = 32;
    SDL_RenderCopy(window->renderer, texture, NULL ,&DestR);
}

SDL_Texture* SDLContext::loadTexture( std::string path )
{

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( window->renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    if(newTexture == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", "p.png", IMG_GetError() );
        //TODO error
    }
    return newTexture;
}

