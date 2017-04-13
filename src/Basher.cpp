#include "Basher.h"

Basher::Basher(int x, int y, int movementSpeed): Entity(x,y, movementSpeed){
    bounds=new BoundingBox(x,y,8,8);
}
Basher::~Basher(){
}
void Basher::Update(){
}
