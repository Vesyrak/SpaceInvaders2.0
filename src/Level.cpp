#include "Level.h"
#include <iostream>
Level::Level(){
}
Level::~Level(){
}
void Level::AddEnemy(Entity* entity){
    enemies.push_back(entity);
}
void Level::Update(){
    CheckCollisions(enemyBullets, playerShip);
    CheckCollisions(playerShipBullets, enemies);
}
void Level::CheckCollisions(std::vector<Entity*> bullets, std::vector<Entity*> entities){
    std::vector<Entity>::iterator i = entities.begin();
    while (i != entities.end())
    {
        bool hit=false;
        std::vector<Entity>::iterator j= bullets.begin();
        while(j!=bullets.end())
        {
            if((*i)->bounds->collidesWith((*j)->bounds))
            {
                entities.erase(i++);
                bullets.erase(j++);
                hit=true;
                break;
            }
            else ++j;
        }
        if(!hit)
            ++i;
    }

}
void Level::Visualise(){
    for(Entity* n:enemies){
        n->Visualise();
    }
    for(Entity* n:playerShip){
        n->Visualise();
    }
    for(Entity* n:enemyBullets){
        n->Visualise();
    }
    for(Entity* n:playerShipBullets){
        n->Visualise();
    }
}

