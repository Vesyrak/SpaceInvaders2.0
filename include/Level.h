#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "PlayerShip.h"
#include <list>
#include "AbstractFactory.h"
class Level{
    public:
        Level(AbstractFactory* factory, Window* window, Input* input, int score, int lives, int difficulty);
        ~Level();
        void Run();
        void Update();
        void Visualise();
        int getScore();
        int getRemainingLives();

    private:
        void MoveEnemies();
        std::vector<Entity*> enemyBullets;
        std::vector<Entity*> playerShipBullets;
        std::vector<Entity*> enemies;
        PlayerShip* playerShip;
        AudioEngine* audioEngine;
        Background* background;
        Window* window;
        AbstractFactory* factory;
    	Timer* frameTimer;
    	Timer* capTimer;
    	Healthbar* healthbar;
    	int countedFrames;
    	int movementCounter;
    	int rows=6;
    	int columns=10;
    	int difficulty;
        bool right;
        int score;
        int scoreHistory;
        int lifeHistory;
        Text* scoreText;
        Text* livesText;
        Text* difficultyText;
        //void CheckBounds();
        void CheckCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities);
        void CheckCollisions(std::vector<Entity*>* bullets, Entity* entity);
};
#endif
