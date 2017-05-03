#include "PlayerShip.h"
#include "AbstractFactory.h"
#include <iostream>
PlayerShip::PlayerShip(AbstractFactory* factory, std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed) :Entity(x, y, movementSpeed) {
	bounds = new BoundingBox(x, y, 8, 8);
	inputHandler = input;
	lives=3;
	this->bulletVector=bulletVector;
	this->factory=factory;
	shootingTimer=factory->createTimer();
	shootingTimer->start();
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
}

void PlayerShip::Shoot() {
	if(shootingTimer->getTicks()>500){
		shootingTimer->start();
		bulletVector->push_back(factory->createLaser(bounds->getX(), bounds->getY(), 1, Up, 2));
	}
}
