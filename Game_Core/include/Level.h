#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "PlayerShip.h"
#include <list>
#include "Screen.h"
#include "AbstractFactory.h"
namespace Game_Core {
	class Level: public Screen {
		public:
			Level(AbstractFactory* factory, Window* window, int score, int lives, int difficulty);
			~Level();
			int GetScore();
			int GetRemainingLives();

		private:
			void Update();
			void Visualise();
			void MoveEnemies();
			void CheckIfTargetReached();
			void CheckCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities);
			void CheckCollisions(std::vector<Entity*>* bullets, Entity* entity);
			AbstractFactory* factory;
			PlayerShip* playerShip;
			AudioEngine* audioEngine;
			Background* background;
			Healthbar* healthbar;
			Text* scoreText;
			Text* livesText;
			Text* difficultyText;
			std::vector<Entity*> enemyBullets;
			std::vector<Entity*> playerShipBullets;
			std::vector<Entity*> enemies;

			int movementCounter;
			int rows = 6;
			int columns = 10;
			int difficulty;
			bool right;
			int score;
			int scoreHistory;
			int lifeHistory;
	};
}
#endif
