#include "Basher.h"
#include "AbstractFactory.h"
#include <algorithm>
namespace Game_Core {

	Basher::Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty): Entity(x, y, 12, 12, 2) {
		this->hp = 45 + 5 * difficulty;
		this->audioEngine = factory->GetAudioEngine();
		this->difficulty=difficulty;
	}
	Basher::~Basher() {
	}
	void Basher::Update() {
	}
    void Basher::Move(InputType dir) {
		switch (dir) {
			case Left:
				bounds->SetX(bounds->GetX() - std::min(0.1+(double)difficulty/50, (double)0.26)*movementSpeed);
				break;
			case Right:
				bounds->SetX(bounds->GetX() + std::min(0.1+(double)difficulty/50, (double)0.26)*movementSpeed);
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

	void Basher::Damage(int damage) {
		audioEngine->PlaySound(Damaged);
		Entity::Damage(damage);
	}
}
