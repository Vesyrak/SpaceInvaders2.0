#include <stdio.h>
#include "SDLContext.h"
namespace Game_SDL {

	SDLContext::SDLContext(SDLWindow* window) {
		this->window = window;
	}

	SDLContext::~SDLContext() {
		std::map<std::string, SDL_Texture*>::iterator itr = textureMap.begin();
		while (itr != textureMap.end()) {
			itr = textureMap.erase(itr);
		}
	}

	//Generates text texture
	SDL_Texture* SDLContext::GenerateText(std::string text, BoundingBox* bounds, int size) {
		TTF_Font* font = TTF_OpenFont("graphics/Kenney Rocket Square.ttf", size);
		SDL_Color White = { 255, 255, 255 };
		SDL_Surface* surfaceMessage = TTF_RenderUTF8_Solid(font, text.c_str(), White);
		bounds->SetWidth(surfaceMessage->w / 2);
		bounds->SetHeight(surfaceMessage->h / 2);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(window->renderer, surfaceMessage);
		SDL_FreeSurface(surfaceMessage);
		TTF_CloseFont(font);
		return texture;
	}

	//Draws (resized) texture to screen
	void SDLContext::Draw(SDL_Texture* texture, BoundingBox* bounds) {
		SDL_Rect DestR;

		DestR.x = window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetX();
		DestR.y = window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetY();
		DestR.w = window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetWidth();
		DestR.h = window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetHeight();
		SDL_RenderCopy(window->renderer, texture, NULL, &DestR);
	}

	//Draws (resized) rectangle to screen
	void SDLContext::DrawRect(SDL_Color* color, BoundingBox* bounds, bool filled) {
		SDL_SetRenderDrawColor(window->renderer, color->r, color->g, color->b, color->a);
		//SDL_RenderClear(window->renderer );
		SDL_Rect DestR;

		DestR.x = window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetX();
		DestR.y = window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetY();
		DestR.w = window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetWidth();
		DestR.h = window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetHeight();
		if (filled)
			SDL_RenderFillRect(window->renderer, &DestR);
		else
			SDL_RenderDrawRect(window->renderer, &DestR);
	}

	//Get texture from texture map, or load it if it isn't in the map
	SDL_Texture* SDLContext::GetTexture(std::string path) {
		std::map<std::string, SDL_Texture*>::iterator it = textureMap.find(path);
		if (it != textureMap.end()) {
			return it->second;
		}
		else
			return loadTexture(path);
	}

	//Load texture from path
	SDL_Texture* SDLContext::loadTexture(std::string path) {

		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
			IMG_GetError());
		}
		else {
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(window->renderer, loadedSurface);
			if (newTexture == NULL) {
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}
		if (newTexture == NULL) {
			printf("Unable to load image %s! SDL_image Error: %s\n", "p.png",
			IMG_GetError());
		}
		textureMap.insert(std::pair<std::string, SDL_Texture*>(path, newTexture));
		return newTexture;
	}

	//Converts logical bounds to actual bounds
	void SDLContext::LogicalToActualCoords(BoundingBox* bounds) {
		bounds->SetX(window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetX());
		bounds->SetY(window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetY());
		bounds->SetWidth(window->screen_width / (double) window->LOGICAL_WIDTH * bounds->GetWidth());
		bounds->SetHeight(window->screen_height / (double) window->LOGICAL_HEIGHT * bounds->GetHeight());
	}
}
