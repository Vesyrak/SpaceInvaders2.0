#ifndef SDLTEXT_H
#define SDLTEXT_H
#include "SDLContext.h"
class SDLText{
public:
	SDLText(SDLContext* context, std::string message, int x, int y);
	~SDLText();
	void Visualise();
	void Update(std::string message);
private:
	SDLContext* context;
	SDL_Texture* texture;
	BoundingBox* bounds;
};
#endif