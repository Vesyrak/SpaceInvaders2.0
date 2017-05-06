#include "Bomber.h"
#include "AbstractFactory.h"
#include <iostream>
Bomber::Bomber(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed):Entity(x, y, movementSpeed){
    bounds=new BoundingBox(x, y,8,8);
    hp=20;
    this->bulletVector=bulletVector;
    this->factory=factory;
    charging=false;
    this->timer=factory->createTimer();
}
Bomber::~Bomber(){
}
void Bomber::Update(){
	if(charging && timer->getTicks()>2000)
	{
		bulletVector->push_back(factory->createLaserBomb(bounds->getX()+bounds->getWidth()/2-2, bounds->getY(), 1, Down, 5));
		charging=false;
	}
	if(!charging &&rand() % 1000==999)
	{
		charging=true;
		timer->start();
	}
}

