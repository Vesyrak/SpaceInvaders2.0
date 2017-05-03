#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include <list>
#include "AbstractFactory.h"
class Level{
    public:
        Level(AbstractFactory* factory, Window* window, Input* input);
        ~Level();
        void AddEnemy(Entity* entity);
        int Run();
        void Update();
        void Visualise();
    private:
        void MoveEnemies();
        std::vector<Entity*> enemyBullets;
        std::vector<Entity*> playerShipBullets;
        std::vector<Entity*> enemies;
        Entity* playerShip;
        Background* background;
        Window* window;
        AbstractFactory* factory;
    	Timer* frameTimer;
    	Timer* capTimer;
    	int countedFrames;
    	int movementCounter;
    	int rows=6;
    	int columns=10;
    	int difficulty;
        bool right;

        //void CheckBounds();
        void CheckCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities);
        void CheckCollisions(std::vector<Entity*>* bullets, Entity* entity);
};
#endif
