#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include <list>
#include "QuadTree.h"
#include "Hivemind.h"
#include "AbstractFactory.h"
class Level{
    public:
        Level(AbstractFactory* factory, Window* window, Input* input);
        ~Level();
        void AddEnemy(Entity* entity);
        void AddPlayerShip(Entity* entity);
        void Update();
        void Visualise();
    private:
        std::vector<Entity*> enemyBullets;
        std::vector<Entity*> playerShipBullets;
        std::vector<Entity*> enemies;
        std::vector<Entity*> playerShip;
        Background* background;
        Overlay* overlay;
        Window* window;
        Hivemind* hivemind;
        AbstractFactory* factory;
        //void CheckBounds();
        void CheckCollisions(std::vector<Entity*> bullets, std::vector<Entity*> entities);

};
#endif
