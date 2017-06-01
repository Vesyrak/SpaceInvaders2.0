#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <string>
#include "Entity.h"
#include "Window.h"
#include "Timer.h"
#include "Input.h"
#include "AudioEngine.h"
using namespace std;

namespace Game_Core {

	class AbstractFactory;

	//Player's moveable ship.
	class PlayerShip: public Entity {
		public:
			PlayerShip(AbstractFactory* factory, std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed);
			virtual ~PlayerShip();
			void Update();
			void Shoot();
			void Move(InputType dir);
			void Damage(int damage) override;
			void PowerUp(PowerUps up);
			int GetLives();
		protected:
			Timer* invincible;
		private:
			void Revive();
			AbstractFactory* factory;
			AudioEngine* audioEngine;
			Input* inputHandler;
			Timer* shootingTimer;
			std::vector<Entity*>* bulletVector;
			int lives;
	};
}
#endif

