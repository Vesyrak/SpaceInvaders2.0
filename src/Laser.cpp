#include "Laser.h"
Laser::Laser(double x, double y, int movementSpeed, InputType direction, int damage): Entity(x,y,movementSpeed){
    this->direction=direction;
    this->hp=damage;
    bounds = new BoundingBox(x, y, 2, 8);
}

void Laser::Update(){
    Move(direction);
}
Laser::~Laser(){
}
