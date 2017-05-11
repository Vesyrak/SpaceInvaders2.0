#include "Basher.h"
#include "AbstractFactory.h"
namespace Game_Core {

Basher::Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty): Entity(x,y,8,8,2){
    this->hp=45+5*difficulty;
    this->audioEngine=factory->getAudioEngine();
}
Basher::~Basher(){
}
void Basher::Update(){
}
void Basher::Damage(int damage){
	audioEngine->PlaySound(Damaged);
	Entity::Damage(damage);
}
}
