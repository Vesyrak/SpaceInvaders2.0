#include "Level.h"
#include <iostream>
Level::Level(AbstractFactory* factory, Window* window, Input* input){
	playerShip.push_back(factory->createPlayerShip( &playerShipBullets,input,40,40, 1));
	hivemind=new Hivemind(1);
	hivemind->Generate(factory,enemies);
	background=factory->createBackground();
	overlay=factory->createOverlay();
	this->window=window;
	this->factory=factory;
}
Level::~Level(){
}
void Level::AddEnemy(Entity* entity){
    enemies.push_back(entity);
}
void Level::AddPlayerShip(Entity* entity){
	playerShip.push_back(entity);
}
void Level::Update(){
	for(Entity* n:playerShip){
	        n->Update();
	}
    hivemind->Update();
    for(Entity* n:enemyBullets){
        n->Update();
    }
    for(Entity* n:playerShipBullets){
        n->Update();
    }
    CheckCollisions(enemyBullets, playerShip);
    CheckCollisions(playerShipBullets, enemies);
}
void Level::CheckCollisions(std::vector<Entity*> bullets, std::vector<Entity*> entities){
    std::vector<Entity*>::iterator i = entities.begin();
    while (i != entities.end())
    {
        bool hit=false;
        std::vector<Entity*>::iterator j= bullets.begin();
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
	window->PrepareRender();
	background->Visualise();
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
    overlay->Visualise();
    window->PresentRender();
}

