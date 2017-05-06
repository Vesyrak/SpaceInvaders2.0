#include "LaserBomb.h"
LaserBomb::LaserBomb( double x, double y, int movementSpeed, InputType direction, int damage): Entity(x,y,movementSpeed){
    this->direction=direction;
    this->hp=damage;
    bounds = new BoundingBox(x, y, 4, 4);
}

void LaserBomb::Update(){
	Move(direction);
}
LaserBomb::~LaserBomb(){
}
