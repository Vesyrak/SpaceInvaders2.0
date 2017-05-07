#ifndef SDLTEXT_H
#define SDLTEXT_H
#include "SDLContext.h"
#include "Text.h"
class SDLText: public Text {
public:
	SDLText(SDLContext* context, std::string message, int x, int y, int size);
	SDLText(SDLContext* context, std::string message, int x, int y );
	~SDLText();
	void Visualise();
	void Update(std::string message);
	void CenterText(BoundingBox* outerBounds);
private:
	SDLContext* context;
	SDL_Texture* texture;
};
#endif
