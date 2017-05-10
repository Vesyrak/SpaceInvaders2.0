//Gotta love Windows
#define __USE_MINGW_ANSI_STDIO 0
#include "Level.h"
#include <iostream>
Level::Level(AbstractFactory* factory, Window* window, Input* input, int score, int lives, int difficulty): Screen(factory, window) {
	this->score=scoreHistory=score;
	playerShip = factory->createPlayerShip(&playerShipBullets, input, 180, 180,1);
	lifeHistory=lives;
	background = factory->createBackground();
	this->factory = factory;
	movementCounter = 0;
	this->difficulty=difficulty;
	audioEngine=factory->getAudioEngine();
	audioEngine->PlayBackground();
	right=true;
	int y = 15;
	for (int j = 0; j < rows; j++) {
		int x = 0;
		if (j < 2)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBomber(&enemyBullets,x, y, difficulty);
				enemies.push_back(enemy);
				x += 15;
			}
		/*else if (j < 4)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBlaster(&enemyBullets,x, y, difficulty);
				enemies.push_back(enemy);
				x += 15;
			}
		else
			for (int i = 0; i <columns; i++) {
				Entity* enemy = factory->createBasher(&enemyBullets,x, y, difficulty);
				enemies.push_back(enemy);
				x += 15;
			}*/
		y += 15;
	}
	scoreText=factory->createText("Score: "+std::to_string(score), 5,185, 16);
	livesText=factory->createText("Lives: "+std::to_string(lives), 150,5, 16);
	healthbar=factory->createHealthbar(playerShip, 5, 5);
	difficultyText=factory->createText("Difficulty: "+std::to_string(difficulty), 120, 185,16);
}
Level::~Level() {
	enemies.clear();
	enemyBullets.clear();
	playerShipBullets.clear();
	delete playerShip;
	delete healthbar;
	delete difficultyText;
	delete scoreText;
	delete livesText;
	delete background;
}

void Level::Update() {
	background->Update();
	playerShip->Update();
	MoveEnemies();
	for (Entity* n : enemies) {
ww			n->Update();
	}
	for (Entity* n : enemyBullets) {
		n->Update();
	}
	for (Entity* n : playerShipBullets) {
		n->Update();
	}
	CheckCollisions(&enemyBullets, playerShip);
	if(playerShip->getHP()<=0 )
	{
		audioEngine->PlaySound(Death);
		if(playerShip->getLives()<0)
			returnValue=1;
		else playerShip->Revive();
	}
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
		scoreText->Update("Score: "+std::to_string(score));
	}
	if(playerShip->getLives()!=lifeHistory)
	{
		lifeHistory=playerShip->getLives();
		livesText->Update("Lives: "+std::to_string(lifeHistory));
	}

	j = enemies.begin();
	while (j < enemies.end()) {
		if ((*j)->getHP() <= 0) {
			delete (*j);
			audioEngine->PlaySound(Death);
			enemies.erase(j++);
			score+=50+50*difficulty;;
		} else
			j++;
	}
	if(enemies.size()==0)
		returnValue=2;
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
	difficultyText->Visualise();
	window->PresentRender();
}

void Level::MoveEnemies() {
	if (movementCounter == (10 - difficulty/4)) {
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
