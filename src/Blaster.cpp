#include "Blaster.h"

Blaster::Blaster(int x, int y, int movementSpeed):Entity(x,y,movementSpeed){
    bounds=new BoundingBox(x,y,8,8);
    hp=30;
}
Blaster::~Blaster(){
}
void Blaster::Update(){
}

