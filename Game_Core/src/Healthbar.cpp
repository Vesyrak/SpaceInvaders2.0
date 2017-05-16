#include "Healthbar.h"
#include "AbstractFactory.h"
namespace Game_Core {

Healthbar::Healthbar(AbstractFactory* factory, Entity* observed, int x, int y){
	this->observed=observed;
	hpText=factory->CreateText("HP: ",x, y, 16 );
	backBounds=new BoundingBox(x+hpText->GetBounds()->GetWidth(),y, 40, 10);
	foreBounds=new BoundingBox(backBounds->GetX()+1,backBounds->GetY()+1,backBounds->GetWidth()-2,backBounds->GetHeight()-2);
}
Healthbar::~Healthbar(){
	delete hpText;
	delete backBounds;
	delete foreBounds;
}
}
