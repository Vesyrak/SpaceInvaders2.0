
//Gotta love Windows
#define __USE_MINGW_ANSI_STDIO 0
#include "Level.h"
#include <iostream>
Level::Level(AbstractFactory* factory, Window* window, Input* input, int score, int lives) {
	this->score=scoreHistory=score;
	playerShip = factory->createPlayerShip(&playerShipBullets, input, 180, 180,1);
	lifeHistory=lives;
	frameTimer = factory->createTimer();
	capTimer = factory->createTimer();
	background = factory->createBackground();
	this->window = window;
	this->factory = factory;
	frameTimer->start();
	countedFrames = 0;
	movementCounter = 0;
	difficulty=1;
	right=true;
	int y = 0;
	for (int j = 0; j < rows; j++) {
		int x = 0;
		if (j < 2)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBomber(&enemyBullets,x, y, 2);
				enemies.push_back(enemy);
				x += 15;
			}
		else if (j < 4)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBlaster(&enemyBullets,x, y, 2);
				enemies.push_back(enemy);
				x += 15;
			}
		else
			for (int i = 0; i <columns; i++) {
				Entity* enemy = factory->createBasher(&enemyBullets,x, y, 2);
				enemies.push_back(enemy);
				x += 15;
			}
		y += 15;
	}
	scoreText=factory->createText(std::to_string(score), 5,5);
	livesText=factory->createText(std::to_string(lives), 160,5);
	healthbar=factory->createHealthbar(playerShip, 50, 5);
}
Level::~Level() {
	std::vector<Entity*>::iterator j = enemies.begin();
	while (j != enemies.end()) {
		delete (*j);
		enemies.erase(j++);
	}
	j = enemyBullets.begin();
	while (j != enemyBullets.end()) {
		delete (*j);
		enemyBullets.erase(j++);
	}
	j = playerShipBullets.begin();
	while (j != playerShipBullets.end()) {
		delete (*j);
		playerShipBullets.erase(j++);
	}

	delete playerShip;
	delete frameTimer;
	delete capTimer;
	delete healthbar;
}
void Level::Run() {
	while (playerShip->getLives()>0  && enemies.size()>0) {
		capTimer->start();
		float avgFPS = countedFrames / (frameTimer->getTicks() / 1000.f);
		if (avgFPS > 2000000) {
			avgFPS = 0;
		}
		Update();
		Visualise();
		int frameTicks = capTimer->getTicks();
		if (frameTicks < 1000 / 60) {
			frameTimer->delay(1000 / 60 - frameTicks);
		}
	}
}
void Level::AddEnemy(Entity* entity) {
	enemies.push_back(entity);
}

void Level::Update() {
	background->Update();
	playerShip->Update();
	MoveEnemies();
	for (Entity* n : enemies) {
			n->Update();
	}
	for (Entity* n : enemyBullets) {
		n->Update();
	}
	for (Entity* n : playerShipBullets) {
		n->Update();
	}
	CheckCollisions(&enemyBullets, playerShip);
	if(playerShip->getHP()<=0 && playerShip->getLives()>0)
		playerShip->Revive();
	CheckCollisions(&playerShipBullets, &enemies);
	if(playerShip->bounds->collidesWith(window->rightBounds))
		playerShip->bounds->setX(window->rightBounds->getX()-playerShip->bounds->getWidth());
	if(playerShip->bounds->collidesWith(window->leftBounds))
		playerShip->bounds->setX(window->leftBounds->getX());
	std::vector<Entity*>::iterator j = playerShipBullets.begin();
	while (j < playerShipBullets.end()) {

		if((*j)->bounds->collidesWith(window->topBounds)){
			delete (*j);
			playerShipBullets.erase(j++);
		}
		else j++;
	}
	healthbar->Update();
	if(score!=scoreHistory){
		scoreHistory=score;
		scoreText->Update(std::to_string(score));
	}
	if(playerShip->getLives()!=lifeHistory)
	{
		lifeHistory=playerShip->getLives();
		livesText->Update(std::to_string(lifeHistory));
	}

	j = enemies.begin();
	while (j < enemies.end()) {
		if ((*j)->getHP() <= 0) {
			delete (*j);
			enemies.erase(j++);
			score+=100;
		} else
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
				delete (*j);
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
			delete (*j);
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
	scoreText->Visualise();
	livesText->Visualise();
	healthbar->Visualise();
	window->PresentRender();
}

void Level::MoveEnemies() {
	if (movementCounter == (10 - difficulty)) {
		movementCounter = 0;
		if (right) {
			for (Entity* e : enemies) {
				if (e->bounds->collidesWith(window->rightBounds)) {
					right = false;
					for (Entity* enemy : enemies) {
						enemy->Move(Down);
						enemy->Move(Down);
					}
					return;
				}
			}
			if (right) {
				for (Entity* enemy : enemies) {
					enemy->Move(Right);
				}
				return;
			}
		} else {
			for (Entity* e : enemies) {
				if (e->bounds->collidesWith(window->leftBounds)) {
					right = true;
					for (Entity* enemy : enemies) {
						enemy->Move(Down);
						enemy->Move(Down);

					}
					return;
				}
			}
			if (!right) {
				for (Entity* enemy : enemies) {
					enemy->Move(Left);
				}
				return;
			}
		}
	} else
		movementCounter++;
}
int Level::getScore(){
	return score;
}
int Level::getRemainingLives(){
	return playerShip->getLives();
}
