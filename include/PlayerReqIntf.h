#ifndef PLAYERREQINTF_H
#define PLAYERREQINTF_H
#include "Entity.h"
#include "Hivemind.h"
#include "AbstractFactory.h"
class Level{
    public:
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
