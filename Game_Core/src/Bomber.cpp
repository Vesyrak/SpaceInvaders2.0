#include "Bomber.h"
#include "AbstractFactory.h"
namespace Game_Core {

	//Constructor sets required parameters
	Bomber::Bomber(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty): Entity(x, y, 12, 12, 2) {
		hp = 20;
		this->bulletVector = bulletVector;
		this->factory = factory;
		this->difficulty = difficulty;
		charging = false;
		this->timer = factory->CreateTimer();
		this->audioEngine = factory->GetAudioEngine();
	}

	Bomber::~Bomber() {
		delete timer;
	}

	//2-stage shooting started by randomizer. First starts "charging", which flashes a bullet on top of the entity, then shoots.
	//Visualisation of the bullet is done by the visualisation layer
	void Bomber::Update() {
		if (charging && timer->GetTicks() > 2000) {
			audioEngine->PlaySound(Shoot);
			bulletVector->push_back(factory->CreateLaserBomb(bounds->GetX() + bounds->GetWidth() / 2 - 2, bounds->GetY(), 1, Down, 15 + 4 * difficulty));
			charging = false;
		}
		if (!charging && rand() % 1000 == 999) {
			charging = true;
			timer->Start();
		}
	}

	//Moves the enemy faster sideways depending on difficulty, with a max speed. Moving down (or up) is always at the same speed.
    void Bomber::Move(InputType dir) {
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

	void Bomber::Damage(int damage) {
		audioEngine->PlaySound(Damaged);
		Entity::Damage(damage);
	}

}
