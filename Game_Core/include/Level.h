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
		Level(AbstractFactory* factory, Window* window,  int score, int lives, int difficulty);
		~Level();
		int getScore();
		int getRemainingLives();

	private:
		void Update();
		void Visualise();
		void MoveEnemies();
		void CheckIfTargetReached();
		std::vector<Entity*> enemyBullets;
		std::vector<Entity*> playerShipBullets;
		std::vector<Entity*> enemies;
		PlayerShip* playerShip;
		AudioEngine* audioEngine;
		Background* background;
		AbstractFactory* factory;
		Healthbar* healthbar;
		int movementCounter;
		int rows = 6;
		int columns = 10;
		int difficulty;
		bool right;
		int score;
		int scoreHistory;
		int lifeHistory;
		Text* scoreText;
		Text* livesText;
		Text* difficultyText;
		void CheckCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities);
		void CheckCollisions(std::vector<Entity*>* bullets, Entity* entity);
};}
#endif
