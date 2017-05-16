#ifndef BOMBER_H
#define BOMBER_H
#include "Entity.h"
#include "Timer.h"
#include "AudioEngine.h"
namespace Game_Core {
	class AbstractFactory;
	class Bomber: public Entity {
		public:
			Bomber(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int x, int y, int difficulty);
			~Bomber();
			void Update();
			void Attack();
			void Damage(int damage);
		protected:
			bool charging;
			Timer* timer;
			int difficulty;
			AudioEngine* audioEngine;
		private:
			AbstractFactory* factory;
			std::vector<Entity*>* bulletVector;

	};
}
#endif
