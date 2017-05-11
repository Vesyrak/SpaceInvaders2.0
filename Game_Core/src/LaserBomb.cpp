#include "LaserBomb.h"
namespace Game_Core {

LaserBomb::LaserBomb( double x, double y, int movementSpeed, InputType direction, int damage): Entity(x,y,4,4,movementSpeed){
    this->direction=direction;
    this->hp=damage;
}

void LaserBomb::Update(){
	Move(direction);
}
LaserBomb::~LaserBomb(){
}
}
