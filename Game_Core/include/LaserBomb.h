#ifndef LASERBOMB_H
#define LASERBOMB_H
#include "Entity.h"

namespace Game_Core {

	//Implementation of a LaserBomb, used by the Bomber.
	class LaserBomb: public Entity {
		public:
			LaserBomb(double x, double y, int movementSpeed, InputType direction, int damage);
			~LaserBomb();
			void Update();
		private:
			InputType direction;
	};
}
#endif
