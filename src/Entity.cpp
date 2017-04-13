#include "Entity.h"
#include <iostream>
using namespace std;
Entity::Entity(int x, int y, int movementSpeed){
    this->movementSpeed=movementSpeed;
}
Entity::~Entity(){
    delete bounds;
}
void Entity::Move(InputType dir){
    switch(dir){
        case Left:
            bounds->setX(bounds->getX()-movementSpeed);
            break;
        case Right:
            bounds->setX(bounds->getX()+movementSpeed);
            break;
        case Up:
            bounds->setY(bounds->getY()-movementSpeed);
            break;
        case Down:
            bounds->setY(bounds->getY()+movementSpeed);
            break;
        default:
            return;
    }
    std::cout<<movementSpeed<<","<<bounds->getX()<<":"<<bounds->getY()<<std::endl;
}
