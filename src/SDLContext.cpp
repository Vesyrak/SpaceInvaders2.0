#include<stdio.h>
#include "SDLContext.h"
SDLContext::SDLContext(SDLWindow* window) {
	this->window = window;
}
SDLContext::~SDLContext() {
	std::map<std::string, SDL_Texture*>::iterator itr = textureMap.begin();
	while (itr != textureMap.end()) {
	       itr = textureMap.erase(itr);
	}
}

SDL_Texture* SDLContext::GenerateText(std::string text, BoundingBox* bounds,
		int size) {

	TTF_Font* font = TTF_OpenFont("graphics/bitbold.ttf", size);

	SDL_Color White = { 255, 255, 255 }; // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderUTF8_Solid(font, text.c_str(),
			White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	bounds->setWidth(surfaceMessage->w / 2);
	bounds->setHeight(surfaceMessage->h / 2);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer,
			surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(font);
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
void SDLContext::DrawRect(SDL_Color* color, BoundingBox* bounds, bool filled) {
	SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b,
			color->a);
	//SDL_RenderClear(window->renderer );
	SDL_Rect DestR;

	DestR.x = window->screen_width / (double) window->logical_width
			* bounds->getX();
	DestR.y = window->screen_height / (double) window->logical_height
			* bounds->getY();
	DestR.w = window->screen_width / (double) window->logical_width
			* bounds->getWidth();
	DestR.h = window->screen_height / (double) window->logical_width
			* bounds->getHeight();
	if (filled)
		SDL_RenderFillRect(window->renderer, &DestR);
	else
		SDL_RenderDrawRect(window->renderer, &DestR);
}
SDL_Texture* SDLContext::getTexture(std::string path){
	std::map<std::string,SDL_Texture*>::iterator it = textureMap.find(path);
	if(it!=textureMap.end()){
		return it->second;
	}
	else return loadTexture(path);
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
		newTexture = SDL_CreateTextureFromSurface(window->renderer,loadedSurface);
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
	}
	textureMap.insert(std::pair<std::string,SDL_Texture*>(path, newTexture));
	return newTexture;
}
void SDLContext::LogicalToActualCoords(BoundingBox* bounds) {
	bounds->setX(
			window->screen_width / (double) window->logical_width
					* bounds->getX());
	bounds->setY(
			window->screen_height / (double) window->logical_height
					* bounds->getY());
	bounds->setWidth(
			window->screen_width / (double) window->logical_width
					* bounds->getWidth());
	bounds->setHeight(
			window->screen_height / (double) window->logical_width
					* bounds->getHeight());
}
