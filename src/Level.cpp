#include "Level.h"
#include <iostream>
Level::Level(AbstractFactory* factory, Window* window, Input* input) {
	playerShip = factory->createPlayerShip(&playerShipBullets, input, 180, 180, 1);
	hivemind = new Hivemind(1);
	hivemind->Generate(factory, &enemies);
	background = factory->createBackground();
	this->window = window;
	this->factory = factory;
}
Level::~Level() {
	std::vector<Entity*>::iterator j = enemies.begin();
	while (j != enemies.end()) {
		delete(*j);
		enemies.erase(j++);
	}
	j = enemyBullets.begin();
	while (j != enemyBullets.end()) {
		delete(*j);
		enemyBullets.erase(j++);
	}
	j = playerShipBullets.begin();
	while (j != playerShipBullets.end()) {
		delete(*j);
		playerShipBullets.erase(j++);
	}

	delete playerShip;
	delete hivemind;
}

void Level::AddEnemy(Entity* entity) {
	enemies.push_back(entity);
}

void Level::Update() {
	background->Update();
	playerShip->Update();
	hivemind->Update();
	for (Entity* n : enemyBullets) {
		n->Update();
	}
	for (Entity* n : playerShipBullets) {
		n->Update();
	}
	CheckCollisions(&enemyBullets, playerShip);
	CheckCollisions(&playerShipBullets, &enemies);
	std::vector<Entity*>::iterator j = enemies.begin();
	while (j < enemies.end()) {
		if ((*j)->getHP() <= 0)
			enemies.erase(j++);
		else
			j++;
	}
}
void Level::CheckCollisions(std::vector<Entity*>* bullets,
		std::vector<Entity*>* entities) {
	std::vector<Entity*>::iterator i = entities->begin();
	while (i < entities->end()) {
		bool hit = false;
		std::vector<Entity*>::iterator j = bullets->begin();
		while (j < bullets->end()) {
			if ((*i)->bounds->collidesWith((*j)->bounds)) {
				(*i)->Damage((*j)->getHP());
				delete(*j);
				bullets->erase(j++);
				hit = true;
				break;
			} else
				++j;
		}
		if (!hit)
			++i;
	}

}
void Level::CheckCollisions(std::vector<Entity*>* bullets, Entity* entity) {
	std::vector<Entity*>::iterator j = bullets->begin();
	while (j < bullets->end()) {
		if (entity->bounds->collidesWith((*j)->bounds)) {
			entity->Damage((*j)->getHP());
			delete(*j);
			bullets->erase(j++);
			break;
		} else
			++j;
	}

}
void Level::Visualise() {
	window->PrepareRender();
	background->Visualise();
	for (Entity* n : enemies) {
		n->Visualise();
	}
	playerShip->Visualise();

	for (Entity* n : enemyBullets) {
		n->Visualise();
	}
	for (Entity* n : playerShipBullets) {
		n->Visualise();
	}
	window->PresentRender();
}

