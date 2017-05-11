#include "Healthbar.h"
#include "AbstractFactory.h"
namespace Game_Core {

Healthbar::Healthbar(AbstractFactory* factory, Entity* observed, int x, int y){
	this->observed=observed;
	hpText=factory->createText("HP: ",x, y, 16 );
	backBounds=new BoundingBox(x+hpText->bounds->getWidth(),y, 40, 10);
	foreBounds=new BoundingBox(backBounds->getX()+1,backBounds->getY()+1,backBounds->getWidth()-2,backBounds->getHeight()-2);
}
Healthbar::~Healthbar(){
	delete backBounds;
	delete foreBounds;
}
}
