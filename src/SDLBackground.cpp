#include "SDLBackground.h"

SDLBackground::SDLBackground(SDLContext* context):Background(){
    this->context=context;
    image=context->loadTexture("graphics/background.png");
}
SDLBackground::~SDLBackground(){
    SDL_DestroyTexture(image);
}

void SDLBackground::Visualise(){
    context->Draw(image, bounds);
}

