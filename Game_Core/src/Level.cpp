//Gotta love Windows
#define __USE_MINGW_ANSI_STDIO 0
#include "Level.h"
#include <iostream>
namespace Game_Core {

	Level::Level(AbstractFactory* factory, Window* window, int score, int lives, int difficulty) :Screen(factory, window) {
		this->score = scoreHistory = score;
		lifeHistory = lives;
		playerShip = factory->CreatePlayerShip(&playerShipBullets, lives, 100, 180, 1);
		background = factory->CreateBackground();
		audioEngine = factory->GetAudioEngine();
		this->factory = factory;
		movementCounter = 0;
		this->difficulty = difficulty;
		audioEngine->PlayBackground();
		right = true;
		int y = 15;
		for (int j = 0; j < rows; j++) {
			int x = 0;
			if (j < 2)
				for (int i = 0; i < columns; i++) {
					enemies.push_back(factory->CreateBomber(&enemyBullets, x, y, difficulty));
					x += 15;
				}
			else if (j < 5)
				for (int i = 0; i < columns; i++) {
					Entity* enemy = factory->CreateBlaster(&enemyBullets, x, y, difficulty);
					enemies.push_back(enemy);
					x += 15;
				}
			else
				for (int i = 0; i < columns; i++) {
					Entity* enemy = factory->CreateBasher(&enemyBullets, x, y, difficulty);
					enemies.push_back(enemy);
					x += 15;
				}
			y += 15;
		}
		scoreText = factory->CreateText("Score: " + std::to_string(score), 5, 185, 16);
		livesText = factory->CreateText("Lives: " + std::to_string(lives), 150, 5, 16);
		healthbar = factory->CreateHealthbar(playerShip, 5, 5);
		difficultyText = factory->CreateText("Difficulty: " + std::to_string(difficulty), 120, 185, 16);
	}
	Level::~Level() {
		for (std::vector<Entity*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
			delete (*it);
		}
		enemies.clear();
		for (std::vector<Entity*>::iterator it = enemyBullets.begin(); it != enemyBullets.end(); ++it) {
			delete (*it);
		}
		enemyBullets.clear();
		for (std::vector<Entity*>::iterator it = playerShipBullets.begin(); it != playerShipBullets.end(); ++it) {
			delete (*it);
		}
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
			n->Update();
		}
		for (Entity* n : enemyBullets) {
			n->Update();
		}
		for (Entity* n : playerShipBullets) {
			n->Update();
		}
		CheckCollisions(&enemyBullets, playerShip);
		CheckCollisions(&playerShipBullets, &enemies);
		if (playerShip->GetBounds()->CollidesWith(window->GetRightBounds()))
			playerShip->GetBounds()->SetX(window->GetRightBounds()->GetX() - playerShip->GetBounds()->GetWidth());
		if (playerShip->GetBounds()->CollidesWith(window->GetLeftBounds()))
			playerShip->GetBounds()->SetX(window->GetLeftBounds()->GetX() + window->GetLeftBounds()->GetWidth());
		std::vector<Entity*>::iterator j = playerShipBullets.begin();
		while (j < playerShipBullets.end()) {

			if ((*j)->GetBounds()->CollidesWith(window->GetTopBounds())) {
				delete (*j);
				playerShipBullets.erase(j++);
			}
			else
				j++;
		}
		healthbar->Update();
		if (score != scoreHistory) {
			scoreHistory = score;
			scoreText->Update("Score: " + std::to_string(score));
		}
		if (playerShip->GetLives() != lifeHistory) {
			lifeHistory = playerShip->GetLives();
			livesText->Update("Lives: " + std::to_string(lifeHistory));
		}

		j = enemies.begin();
		while (j < enemies.end()) {
			if ((*j)->GetHP() <= 0) {
				delete (*j);
				audioEngine->PlaySound(Death);
				enemies.erase(j++);
				score += 50 + 50 * difficulty;
			}
			else
				j++;
		}
		if (enemies.size() == 0)
			returnValue = 2;
		CheckIfTargetReached();
		if (playerShip->GetLives() < 0)
			returnValue = 1;
	}
	void Level::CheckCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities) {
		std::vector<Entity*>::iterator i = entities->begin();
		while (i < entities->end()) {
			bool hit = false;
			std::vector<Entity*>::iterator j = bullets->begin();
			while (j < bullets->end()) {
				if ((*i)->GetBounds()->CollidesWith((*j)->GetBounds())) {
					(*i)->Damage((*j)->GetHP());
					delete (*j);
					bullets->erase(j++);
					hit = true;
					break;
				}
				else
					++j;
			}
			if (!hit)
				++i;
		}

	}
	void Level::CheckCollisions(std::vector<Entity*>* bullets, Entity* entity) {
		std::vector<Entity*>::iterator j = bullets->begin();
		while (j < bullets->end()) {
			if (entity->GetBounds()->CollidesWith((*j)->GetBounds())) {
				entity->Damage((*j)->GetHP());
				delete (*j);
				bullets->erase(j++);
				break;
			}
			else
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
		if (movementCounter == (10 - difficulty / 4)) {
			movementCounter = 0;
			if (right) {
				for (Entity* e : enemies) {
					if (e->GetBounds()->CollidesWith(window->GetRightBounds())) {
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
			}
			else {
				for (Entity* e : enemies) {
					if (e->GetBounds()->CollidesWith(window->GetLeftBounds())) {
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
		}
		else
			movementCounter++;
	}

	void Level::CheckIfTargetReached() {
		for (Entity* enemy : enemies) {
			if (enemy->GetBounds()->GetY() + enemy->GetBounds()->GetHeight() > 170) {
				playerShip->Damage(100);
				returnValue = 3;
				return;
			}
		}
	}

	int Level::GetScore() {
		return score;
	}

	int Level::GetRemainingLives() {
		return playerShip->GetLives();
	}
}
