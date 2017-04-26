#include "PlayerShip.h"
#include "AbstractFactory.h"
#include <iostream>
PlayerShip::PlayerShip(AbstractFactory* factory, std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed) :Entity(x, y, movementSpeed) {
	bounds = new BoundingBox(x, y, 8, 8);
	inputHandler = input;
	hp = 100;
	lives=3;
	this->bulletVector=bulletVector;
	this->factory=factory;
}
PlayerShip::~PlayerShip() {
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
	bulletVector->push_back(factory->createLaser(bounds->getX(), bounds->getY(), 1, Up, 2));

}
