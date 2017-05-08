#include "SDLText.h"

SDLText::SDLText(SDLContext* context, std::string message, int x, int y, int size):Text(message, x,y, size){
	this->context=context;
	this->texture=this->context->GenerateText(message, bounds, size);
}
SDLText::SDLText(SDLContext* context, std::string message, int x, int y):Text(message, x,y, context->defaultFontSize){
	this->context=context;
	this->texture=this->context->GenerateText(message, bounds, size);
}
SDLText::~SDLText(){
	SDL_DestroyTexture(texture);
}
void SDLText::Update(std::string message){
	SDL_DestroyTexture( texture);
	this->texture=this->context->GenerateText(message, bounds, size);

}
void SDLText::Visualise(){
	context->Draw(texture, bounds);
}

void SDLText::CenterText(BoundingBox* outerBounds){

		bounds->setX(outerBounds->getX()+(outerBounds->getWidth()-bounds->getWidth())/2);
		bounds->setY(outerBounds->getY()+(outerBounds->getHeight()-bounds->getHeight())/2);
}
