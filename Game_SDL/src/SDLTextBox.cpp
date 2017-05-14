#include "SDLTextBox.h"
namespace Game_SDL{
SDLTextBox::SDLTextBox(AbstractFactory* factory,SDLContext* context, int x, int y){
	username="Fernando";
	this->context=context;
	borderBounds=new BoundingBox(x, y,60,20);
	inputText=factory->createText(username,x,y);
	input=factory->createInputHandler();
	bordercolor= {196,196,196,255};
}
SDLTextBox::~SDLTextBox(){
	delete borderBounds;
}
void SDLTextBox::Update(){
	input->getCharacterInput(&username);
	if(username.size()>8)
		username=username.substr(0,8);
	inputText->Update(username);
}
void SDLTextBox::Visualise(){
	context->DrawRect(&bordercolor, borderBounds, false);
	inputText->Visualise();
}
}
