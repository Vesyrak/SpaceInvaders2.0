#ifndef BLASTER_H
#define BLASTER_H
#include "Entity.h"
#include "AudioEngine.h"

namespace Game_Core {

	class AbstractFactory;

	//Abstract class for the "Blaster" enemy, Medium HP but increasingly higher attack speed
	class Blaster: public Entity {
		public:
			Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~Blaster();
			void Update();
			void Attack();
	        void Move(InputType dir);
			void Damage(int damage);
		private:
			AbstractFactory* factory;
			AudioEngine* audioEngine;
			std::vector<Entity*>* bulletVector;
			int difficulty;
	};
}

#endif
