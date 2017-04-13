#include "Projectile.h"
Projectile::Projectile(int x, int y, int movementSpeed, InputType direction, int damage): Entity(x,y,movementSpeed){
    this->direction=direction;
    this->damage=damage;
}

void Projectile::Update(){
    Move(direction);
}
Projectile::~Projectile(){
}
