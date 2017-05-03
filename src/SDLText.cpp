#include "SDLText.h"

SDLText::SDLText(SDLContext* context, std::string message, int x, int y):Text(message, x,y){
	this->context=context;
	this->texture=this->context->GenerateText(message, bounds);
}
SDLText::~SDLText(){
	delete texture;
}
void SDLText::Update(std::string message){
	if(texture!=NULL){
		delete texture;
	}
	this->texture=this->context->GenerateText(message, bounds);

}
void SDLText::Visualise(){
	context->Draw(texture, bounds);
}
