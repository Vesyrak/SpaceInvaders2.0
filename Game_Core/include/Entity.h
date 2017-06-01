#ifndef ENTITY_H
#define ENTITY_H
#include "Window.h"
#include "Input.h"
#include "BoundingBox.h"

namespace Game_Core {

	//Enum of possible powerups, only one implemented thus a short enum.
	//Starts at 2 due to using the hp field as an identifier, which is set on 1 by default
	enum PowerUps{LifeUp=2};

	//Base class for entities to use as a template.
	class Entity {
		public:
			Entity(int x, int y, int width, int height, int movementSpeed);
			virtual ~Entity();
			virtual void Update()=0;
			virtual void Visualise()=0;
			virtual void Move(InputType dir);
			virtual void Damage(int damage);
			int GetHP();
			BoundingBox* GetBounds();
		protected:
			int movementSpeed;
			int hp;
			BoundingBox* bounds;
	};
}
#endif

