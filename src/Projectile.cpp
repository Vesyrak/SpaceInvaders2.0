#include "Projectile.h"
Projectile::Projectile(double x, double y, int movementSpeed, InputType direction, int damage): Entity(x,y,movementSpeed){
    this->direction=direction;
    this->damage=damage;
    bounds = new BoundingBox(x, y, 4, 8);
}

void Projectile::Update(){
    Move(direction);
}
Projectile::~Projectile(){
}
