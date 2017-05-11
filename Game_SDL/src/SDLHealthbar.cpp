#include "SDLHealthbar.h"
namespace Game_SDL {

SDLHealthbar::SDLHealthbar(AbstractFactory* factory,SDLContext* context,Entity* observed, int x, int y):Healthbar(factory, observed, x, y){
this->context=context;
this->prevhp=this->starthp=observed->getHP();
backColor={255,255,255,255};
frontColor={0,128,0,255};
}
SDLHealthbar::~SDLHealthbar(){
}
void SDLHealthbar::Update(){
	if(observed->getHP()!=prevhp){
		prevhp=observed->getHP();
		if(observed->getHP()/(double) starthp*100>65)
			frontColor={0,128,0,255};
		else if(observed->getHP()/(double) starthp*100>30)
			frontColor={128,128,0,255};
		else frontColor={128,0,0,255};
		foreBounds->setWidth(observed->getHP()/(double) starthp*(backBounds->getWidth()-2));
	}
}
void SDLHealthbar::Visualise(){
	hpText->Visualise();
	context->DrawRect(&backColor, backBounds,false);
	context->DrawRect(&frontColor, foreBounds, true);
}
}
