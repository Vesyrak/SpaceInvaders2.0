#ifndef LASER_H
#define LASER_H
#include "Entity.h"

namespace Game_Core {

	//Implementation of a Laser, used by PlayerShip & Blaster
	class Laser: public Entity {
		public:
			Laser(double x, double y, int movementSpeed, InputType direction, int damage);
			~Laser();
			void Update();
		private:
			InputType direction;
	};
}
#endif
