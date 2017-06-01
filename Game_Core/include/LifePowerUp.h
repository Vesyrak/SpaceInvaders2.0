#ifndef LIFEPOWERUP_H
#define LIFEPOWERUP_H
#include "PlayerShip.h"

namespace Game_Core{

	//Power up granting an extra life to the player.
	class LifePowerUp: public Entity{
		public:
			LifePowerUp(PlayerShip* playerShip, int x, int y);
			virtual ~LifePowerUp();
			void Update();
		private:
			PlayerShip* playerShip;
	};
}
#endif
