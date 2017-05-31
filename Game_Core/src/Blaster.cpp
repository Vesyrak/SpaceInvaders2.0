#include "Blaster.h"
#include "AbstractFactory.h"
namespace Game_Core {

	Blaster::Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty): Entity(x, y, 12, 12, 2) {
		hp = 30 + 2 * difficulty;
		this->bulletVector = bulletVector;
		this->factory = factory;
		this->difficulty = difficulty;
		this->audioEngine = factory->GetAudioEngine();
	}
	Blaster::~Blaster() {
	}
	void Blaster::Update() {
		if (rand() % (1000 - difficulty * 50) == 1) {
			audioEngine->PlaySound(Shoot);
			bulletVector->push_back(factory->CreateLaser(bounds->GetX() + bounds->GetWidth() / 2, bounds->GetY(), 2, Down, 15));
		}
	}
    void Blaster::Move(InputType dir) {
		switch (dir) {
			case Left:
				bounds->SetX(bounds->GetX() - std::min(0.1+(double)difficulty/50, (double)0.26)*movementSpeed);
				break;
			case Right:
				bounds->SetX(bounds->GetX() + std::min(0.1+(double)difficulty/50,(double)0.26)*movementSpeed);
				break;
			case Up:
				bounds->SetY(bounds->GetY() - movementSpeed);
				break;
			case Down:
				bounds->SetY(bounds->GetY() + movementSpeed);
				break;
			default:
				return;
		}

	}
	void Blaster::Damage(int damage) {
		audioEngine->PlaySound(Damaged);
		Entity::Damage(damage);
	}
}
