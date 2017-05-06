#include "SDLButton.h"
SDLButton::SDLButton(SDLContext* context,std::string text, int x, int y) {
	buttonBounds=new BoundingBox(x,y,100,20);
	textBounds=new BoundingBox(x,y,100,20);
	actualButtonBounds=new BoundingBox(x,y,100,20);
	context->LogicalToActualCoords(actualButtonBounds);
    images[BUTTON_SPRITE_MOUSE_OUT]=context->loadTexture("graphics/button.png");
    images[BUTTON_SPRITE_MOUSE_OVER_MOTION]=context->loadTexture("graphics/button_hover.png");
	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    this->text=context->GenerateText(text, textBounds);
    this->context=context;

}
SDLButton::~SDLButton(){
	delete buttonBounds;
	delete textBounds;
	delete actualButtonBounds;
	for(int i=0; i<5;i++){
		delete images[i];
	}
	delete text;
}
int SDLButton::Update(){
	SDL_Event e;
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT) {
			}
			return handleEvent(&e);

		}
		return 0;
}
void SDLButton::setPosition(int x, int y) {

}

int SDLButton::handleEvent(SDL_Event* e) {
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN
			|| e->type == SDL_MOUSEBUTTONUP) {
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < actualButtonBounds->getX()) {
			inside = false;
		}
		//Mouse is right of the button
		else if (x > actualButtonBounds->getX() + actualButtonBounds->getWidth()) {
			inside = false;
		}
		//Mouse above the button
		else if (y < actualButtonBounds->getY()) {
			inside = false;
		}
		//Mouse below the button
		else if (y >actualButtonBounds->getY() + actualButtonBounds->getHeight()) {
			inside = false;
		}
		//Mouse is outside button
		if (!inside) {
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else {
			//Set mouse over sprite
			switch (e->type) {
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;
			case SDL_MOUSEBUTTONDOWN:
				return 1;
				break;
/*
			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
			break;*/
			}
		}
	}
	return 0;
}
void SDLButton::Visualise()
{
    //Show current button sprite
    context->Draw(images[mCurrentSprite] ,buttonBounds);
    context->Draw(text,textBounds);
}
