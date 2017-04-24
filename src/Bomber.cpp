#include "Bomber.h"

Bomber::Bomber(int x, int y, int movementSpeed):Entity(x, y, movementSpeed){
    bounds=new BoundingBox(x, y,8,8);
    hp=20;
}
Bomber::~Bomber(){
}
void Bomber::Update(){
}

