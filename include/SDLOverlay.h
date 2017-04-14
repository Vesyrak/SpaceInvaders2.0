#ifndef SDLOVERLAY_H
#define SDLOVERLAY_H
#include "Overlay.h"
#include "SDLContext.h"
#include <SDL2/SDL_ttf.h>
class SDLOverlay: public Overlay{
public:
	SDLOverlay(SDLContext* context);
	~SDLOverlay();
	void Visualise() override;
private:
	TTF_Font* font;
	SDLContext* context;
};
#endif
