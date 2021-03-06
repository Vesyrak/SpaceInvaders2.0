#ifndef BASHER_H
#define BASHER_H
#include "Entity.h"
#include "AudioEngine.h"

namespace Game_Core {

	class AbstractFactory;

	//Abstract class for the "Basher" enemy, has no attacks but high HP.
	//Was meant to have a physical attack, not implemented due to time constraints.
	class Basher: public Entity {
		public:
			Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~Basher();
			void Update();
			void Attack();
			void Move(InputType dir);
			void Damage(int damage);
		private:
			int difficulty;
			AudioEngine* audioEngine;
	};
}
#endif
