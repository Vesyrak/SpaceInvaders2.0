#include "PlayerShip.h"
#include "AbstractFactory.h"
#include <iostream>
namespace Game_Core {

PlayerShip::PlayerShip(AbstractFactory* factory,
		std::vector<Entity*>* bulletVector, int lives, int x, int y,
		int movementSpeed) :
		Entity(x, y, 8, 8, movementSpeed) {
	inputHandler = factory->GetInputHandler();
	this->lives = lives;
	this->bulletVector = bulletVector;
	this->factory = factory;
	shootingTimer = factory->CreateTimer();
	shootingTimer->Start();
	this->hp = 100;
	invincible = factory->CreateTimer();
	this->audioEngine = factory->GetAudioEngine();
}
PlayerShip::~PlayerShip() {
	delete shootingTimer;
	delete invincible;
}

void PlayerShip::Update() {
	std::vector<InputType> input = inputHandler->GetInput();
	for (InputType dir : input) {
		if (dir == InputType::Left || dir == InputType::Right)
			Entity::Move(dir);
		if (dir == InputType::Up)
			Shoot();
	}
	if (invincible->IsRunning() && invincible->GetTicks() > 4000)
		invincible->Stop();
}

void PlayerShip::Shoot() {
	if (shootingTimer->GetTicks() > 400) {
		shootingTimer->Start();
		audioEngine->PlaySound(SoundType::Shoot);
		bulletVector->push_back(
				factory->CreateLaser(bounds->GetX() + bounds->GetWidth() / 2,
						bounds->GetY(), 2, Up, 20));
	}
}
int PlayerShip::GetLives() {
	return lives;
}
void PlayerShip::Revive() {
	hp = 100;
	bounds->SetX(100);
	invincible->Start();
}
void PlayerShip::Damage(int damage) {
	audioEngine->PlaySound(Damaged);

	if (!invincible->IsRunning()) {
		Entity::Damage(damage);
	}
	if(hp<=0){
		audioEngine->PlaySound(Death);
		lives--;
		if( lives>0)
			Revive();
	}
}
}
