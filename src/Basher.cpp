#include "Basher.h"
#include "AbstractFactory.h"
Basher::Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty): Entity(x,y,8,8,2){
    this->hp=45+5*difficulty;
}
Basher::~Basher(){
}
void Basher::Update(){
}
