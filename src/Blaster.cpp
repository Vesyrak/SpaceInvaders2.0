#include "Blaster.h"
#include "AbstractFactory.h"

Blaster::Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed):Entity(x,y,movementSpeed){
    bounds=new BoundingBox(x,y,8,8);
    hp=30;
    this->bulletVector=bulletVector;
    this->factory=factory;
}
Blaster::~Blaster(){
}
void Blaster::Update(){
	if(rand() % 1000==999){
		bulletVector->push_back(factory->createLaser(bounds->getX()+bounds->getWidth()/2, bounds->getY(), 2, Down, 30));
	}
}

