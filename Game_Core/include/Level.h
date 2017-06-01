#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "PlayerShip.h"
#include <list>
#include "Screen.h"
#include "AbstractFactory.h"

namespace Game_Core {

	//Level class, all the actual action is dirigated here
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
			void CheckPlayerBulletCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities);
			void CheckEnemyBulletCollisions(std::vector<Entity*>* bullets, Entity* entity);
			void CheckPowerUpCollisions(std::vector<Entity*>* powerUps, PlayerShip* entity);
			void UpdateCollisions();
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
			std::vector<Entity*> powerups;
			int rows = 6;
			int columns = 9;
			int difficulty;
			bool right;
			int score;
			int scoreHistory;
			int lifeHistory;
	};
}
#endif
