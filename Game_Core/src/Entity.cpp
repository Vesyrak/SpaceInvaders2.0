#include "Entity.h"
using namespace std;
namespace Game_Core {
	Entity::Entity(int x, int y, int width, int height, int movementSpeed) {
		this->movementSpeed = movementSpeed;
		hp = 1;
		bounds = new BoundingBox(x, y, width, height);
	}
	Entity::~Entity() {
		delete bounds;
	}
	void Entity::Move(InputType dir) {
		switch (dir) {
			case Left:
				bounds->SetX(bounds->GetX() - movementSpeed);
				break;
			case Right:
				bounds->SetX(bounds->GetX() + movementSpeed);
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
	void Entity::Damage(int damage) {
		hp = hp - damage;
	}
	BoundingBox* Entity::GetBounds() {
		return bounds;
	}
	int Entity::GetHP() {
		return hp;
	}
}
