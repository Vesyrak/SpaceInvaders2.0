#include "Laser.h"
namespace Game_Core {

Laser::Laser(double x, double y, int movementSpeed, InputType direction, int damage): Entity(x,y,2,8,movementSpeed){
    this->direction=direction;
    this->hp=damage;
}

void Laser::Update(){
    Move(direction);
}
Laser::~Laser(){
}
}
