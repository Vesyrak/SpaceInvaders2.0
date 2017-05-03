#include<stdio.h>
#include "SDLContext.h"
SDLContext::SDLContext(SDLWindow* window) {
	this->window = window;
	font=NULL;
}
void SDLContext::InitializeFont(){
	font = NULL;
	font = TTF_OpenFont("graphics/Unique.ttf", 38);
	if (font == NULL) {
		std::cout << "Failed to load lazy font! SDL_ttf Error:"<< TTF_GetError() << std::endl;
	}
}
SDL_Texture* SDLContext::GenerateText(std::string text, BoundingBox* bounds) {
	if(font==NULL)
		InitializeFont();
	SDL_Color White = { 255, 255, 255 }; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(),
			White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	bounds->setWidth(surfaceMessage->w/2 );
	bounds->setHeight(surfaceMessage->h/2);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer,
			surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	return texture;
}

void SDLContext::Draw(SDL_Texture* texture, BoundingBox* bounds) {
	SDL_Rect DestR;

	DestR.x = window->screen_width / (double) window->logical_width
			* bounds->getX();
	DestR.y = window->screen_height / (double) window->logical_height
			* bounds->getY();
	DestR.w = window->screen_width / (double) window->logical_width
			* bounds->getWidth();
	DestR.h = window->screen_height / (double) window->logical_width
			* bounds->getHeight();
	SDL_RenderCopy(window->renderer, texture, NULL, &DestR);
}

SDL_Texture* SDLContext::loadTexture(std::string path) {

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
				IMG_GetError());
	} else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(window->renderer,
				loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	if (newTexture == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", "p.png",
				IMG_GetError());
		//TODO error
	}
	return newTexture;
}
void SDLContext::LogicalToActualCoords(BoundingBox* bounds){
	bounds->setX(window->screen_width / (double) window->logical_width * bounds->getX());
	bounds->setY(window->screen_height / (double) window->logical_height
			* bounds->getY());
	bounds->setWidth( window->screen_width / (double) window->logical_width
			* bounds->getWidth());
	bounds->setHeight(window->screen_height / (double) window->logical_width
			* bounds->getHeight());
}
