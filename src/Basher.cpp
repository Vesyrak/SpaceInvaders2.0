#include "Basher.h"
#include "AbstractFactory.h"
Basher::Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed): Entity(x,y, movementSpeed){
    bounds=new BoundingBox(x,y,8,8);
    this->hp=50;
}
Basher::~Basher(){
}
void Basher::Update(){
}
