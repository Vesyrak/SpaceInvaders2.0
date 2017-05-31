#ifndef POWERUP_H
#define POWERUP_H
#include "PlayerShip.h"

namespace Game_Core{
	class PowerUp: public Entity{
		public:
			PowerUp(int x, int y, int movementSpeed);
			virtual ~LifePowerUp();
			virtual Activate()=0;
	};
}
