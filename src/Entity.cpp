#include "Entity.h"
#include <iostream>
using namespace std;
Entity::Entity(int x, int y,int width, int height, int movementSpeed){
    this->movementSpeed=movementSpeed;
  	hp=1;
  	bounds=new BoundingBox(x,y, width, height);
}
Entity::~Entity(){
    delete bounds;
}
int Entity::getHP(){
	return hp;
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
   // std::cout<<movementSpeed<<","<<bounds->getX()<<":"<<bounds->getY()<<std::endl;
}
void Entity::Damage(int damage){
	cout<<hp<<","<<damage<<endl;
	hp=hp-damage;
	cout<<hp<<","<<damage<<endl;
}

