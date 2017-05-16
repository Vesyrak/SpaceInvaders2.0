#ifndef ENTITY_H
#define ENTITY_H
#include "Window.h"
#include "Input.h"
#include "BoundingBox.h"
namespace Game_Core {
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

