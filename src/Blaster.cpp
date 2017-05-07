#include "Blaster.h"
#include "AbstractFactory.h"

Blaster::Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty):Entity(x,y,8,8,2){
    hp=30+2*difficulty;
    this->bulletVector=bulletVector;
    this->factory=factory;
    this->difficulty=difficulty;
}
Blaster::~Blaster(){
}
void Blaster::Update(){
	if(rand() %( 1000-difficulty*50)==1){
		bulletVector->push_back(factory->createLaser(bounds->getX()+bounds->getWidth()/2, bounds->getY(), 2, Down, 15));
	}
}

