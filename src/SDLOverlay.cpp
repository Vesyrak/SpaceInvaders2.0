#include "SDLOverlay.h"

SDLOverlay::SDLOverlay(SDLContext* context){
	font=NULL;
	 font = TTF_OpenFont("graphics/Unique.ttf", 24);
	 if( font == NULL )
	    {
	        std::cout<< "Failed to load lazy font! SDL_ttf Error:"<< TTF_GetError() <<std::endl;
	    }
	 this->context=context;
}
SDLOverlay::~SDLOverlay(){

}

void SDLOverlay::Visualise(){
	SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Yo Whadup", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	SDL_Texture* texture=context->GenerateText(surfaceMessage);
	context->Draw(texture,new BoundingBox(0,0,surfaceMessage->w/4,surfaceMessage->h/4));
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(texture);
}
