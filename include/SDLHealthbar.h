#ifndef SDLHEALTHBAR_H
#define SDLHEALTHBAR_H
#include "Healthbar.h"
#include "SDLContext.h"
class SDLHealthbar: public Healthbar{
public:
	SDLHealthbar(AbstractFactory* factory,SDLContext* context, Entity* observed, int x, int y);
	~SDLHealthbar();
	 void Visualise() override;
	 void Update() override;
private:
	SDLContext* context;
	int starthp;
	SDL_Color backColor;
	SDL_Color frontColor;
	int prevhp;
};
#endif
