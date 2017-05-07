#include "PlayerShip.h"
#include "AbstractFactory.h"
#include <iostream>
PlayerShip::PlayerShip(AbstractFactory* factory, std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed) :Entity(x, y,8,8, movementSpeed) {
	inputHandler = input;
	lives=3;
	this->bulletVector=bulletVector;
	this->factory=factory;
	shootingTimer=factory->createTimer();
	shootingTimer->start();
	this->hp=100;
	invincible=factory->createTimer();
}
PlayerShip::~PlayerShip() {
	delete bounds;
	delete shootingTimer;
}
void PlayerShip::Move(InputType dir) {

}
void PlayerShip::Update() {
	std::vector<InputType> input = inputHandler->getInput();
	for (InputType dir : input) {
		if (dir == InputType::Left|| dir == InputType::Right)
			Entity::Move(dir);
		if(dir==InputType::Up)
			Shoot();
	}
	if(invincible->isRunning()&& invincible->getTicks()>4000)
		invincible->stop();
}

void PlayerShip::Shoot() {
	if(shootingTimer->getTicks()>500){
		shootingTimer->start();
		bulletVector->push_back(factory->createLaser(bounds->getX()+bounds->getWidth()/2, bounds->getY(), 2, Up, 20));
	}
}
int PlayerShip::getLives(){
	return lives;
}
void PlayerShip::Revive(){
	hp=100;
	bounds->setX(100);
	lives--;
	invincible->start();
}
void PlayerShip::Damage(int damage){
	if(!invincible->isRunning()){
		Entity::Damage(damage);
	}
}
