#include "Healthbar.h"
Healthbar::Healthbar(Entity* observed, int x, int y){
	this->observed=observed;
	backBounds=new BoundingBox(x,y, 40, 10);
	foreBounds=new BoundingBox(backBounds->getX()+1,backBounds->getY()+1,backBounds->getWidth()-2,backBounds->getHeight()-2);

}
Healthbar::~Healthbar(){
	delete backBounds;
	delete foreBounds;
}
