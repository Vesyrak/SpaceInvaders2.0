//Gotta love Windows
#define __USE_MINGW_ANSI_STDIO 0
#include "Level.h"
#include <iostream>

namespace Game_Core {

	//Sets standard parameters and generates enemies.
	Level::Level(AbstractFactory* factory, Window* window, int score, int lives, int difficulty) :
			Screen(factory, window) {
		this->score = scoreHistory = score;
		lifeHistory = lives;
		playerShip = factory->CreatePlayerShip(&playerShipBullets, lives, 100, 180, 1);
		background = factory->CreateBackground();
		audioEngine = factory->GetAudioEngine();
		this->factory = factory;
		this->difficulty = difficulty;
		audioEngine->PlayBackground();
		right = true;
		int y = 15;
		for (int j = 0; j < rows; j++) {
			int x = 0;
			for (int i = 0; i < columns; i++) {
				if (j < 2)
					enemies.push_back(factory->CreateBomber(&enemyBullets, x, y, difficulty));
				else if (j < 5)
					enemies.push_back(factory->CreateBlaster(&enemyBullets, x, y, difficulty));
				else
					enemies.push_back(factory->CreateBasher(&enemyBullets, x, y, difficulty));
				x += 16;
			}
			y += 15;
		}
		scoreText = factory->CreateText("Score: " + std::to_string(score), 5, 190, 16);
		livesText = factory->CreateText("Lives: " + std::to_string(lives), 150, 5, 16);
		healthbar = factory->CreateHealthbar(playerShip, 5, 5);
		difficultyText = factory->CreateText("Difficulty: " + std::to_string(difficulty), 110, 190, 16);
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
		for (std::vector<Entity*>::iterator it = powerups.begin(); it != powerups.end(); ++it) {
			delete (*it);
		}
		powerups.clear();
		delete playerShip;
		delete healthbar;
		delete difficultyText;
		delete scoreText;
		delete livesText;
		delete background;
	}

	//Updates the entire level, from entities to player to collision to UI
	void Level::Update() {
		//Update entities
		for (InputType dir : input->inputVector) {
			playerShip->Move(dir);
		}
		MoveEnemies();
		playerShip->Update();
		for (Entity* n : enemies) {
			n->Update();
		}
		for (Entity* n : enemyBullets) {
			n->Update();
		}
		for (Entity* n : playerShipBullets) {
			n->Update();
		}
		for (Entity* n : powerups) {
			n->Update();
		}
		UpdateCollisions();

		//Update UI
		background->Update();
		healthbar->Update();
		if (score != scoreHistory) {
			scoreHistory = score;
			scoreText->Update("Score: " + std::to_string(score));
		}
		if (playerShip->GetLives() != lifeHistory) {
			lifeHistory = playerShip->GetLives();
			livesText->Update("Lives: " + std::to_string(lifeHistory));
		}

		//Checks termination conditions
		if (enemies.size() == 0)
			returnValue = NextLevel;
		CheckIfTargetReached();
		if (playerShip->GetLives() < 0)
			returnValue = GameOver;
	}

	void Level::UpdateCollisions() {
		CheckEnemyBulletCollisions(&enemyBullets, playerShip);
		CheckPowerUpCollisions(&powerups, playerShip);
		CheckPlayerBulletCollisions(&playerShipBullets, &enemies);
		if (playerShip->GetBounds()->CollidesWith(window->GetRightBounds()))
			playerShip->GetBounds()->SetX(window->GetRightBounds()->GetX() - playerShip->GetBounds()->GetWidth());
		if (playerShip->GetBounds()->CollidesWith(window->GetLeftBounds()))
			playerShip->GetBounds()->SetX(window->GetLeftBounds()->GetX() + window->GetLeftBounds()->GetWidth());
	}

	//Checks for powerup collisions with the enemies or the top of the screen
	void Level::CheckPlayerBulletCollisions(std::vector<Entity*>* bullets, std::vector<Entity*>* entities) {
		std::vector<Entity*>::iterator i = entities->begin();
		while (i < entities->end()) {
			std::vector<Entity*>::iterator j = bullets->begin();
			while (j < bullets->end()) {
				if ((*i)->GetBounds()->CollidesWith((*j)->GetBounds())) {
					(*i)->Damage((*j)->GetHP());
					delete (*j);
					bullets->erase(j++);
					if ((*i)->GetHP() <= 0) {
						if (rand() % 40 == 0) {
							powerups.push_back(factory->CreateLifePowerUp(playerShip, (*i)->GetBounds()->GetX(), (*i)->GetBounds()->GetY()));
						}
						delete (*i);
						audioEngine->PlaySound(Death);
						enemies.erase(i);
						score += 50 + 50 * difficulty;
						break;
					}
				}
				else if ((*j)->GetBounds()->CollidesWith(window->GetTopBounds())) {
					delete (*j);
					bullets->erase(j++);
				}
				else
					++j;
			}
			++i;
		}
	}

	//Checks for bullet collisions with the player or the bottom of the screen
	void Level::CheckEnemyBulletCollisions(std::vector<Entity*>* bullets, Entity* entity) {
		std::vector<Entity*>::iterator j = bullets->begin();
		while (j < bullets->end()) {
			if (entity->GetBounds()->CollidesWith((*j)->GetBounds())) {
				entity->Damage((*j)->GetHP());
				delete (*j);
				bullets->erase(j++);
				break;
			}
			else if ((*j)->GetBounds()->CollidesWith(window->GetBottomBounds())) {
				delete (*j);
				bullets->erase(j++);
			}
			else
				++j;
		}
	}

	//Checks for powerup collisions with the player or the bottom of the screen
	void Level::CheckPowerUpCollisions(std::vector<Entity*>* powerUps, PlayerShip* entity) {
		std::vector<Entity*>::iterator j = powerUps->begin();
		while (j < powerUps->end()) {
			if (entity->GetBounds()->CollidesWith((*j)->GetBounds())) {
				entity->PowerUp(static_cast<PowerUps>((*j)->GetHP()));
				delete (*j);
				powerUps->erase(j++);
				break;
			}
			else if ((*j)->GetBounds()->CollidesWith(window->GetBottomBounds())) {
				delete (*j);
				powerUps->erase(j++);
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
		for (Entity* n : powerups) {
			n->Visualise();
		}
		scoreText->Visualise();
		livesText->Visualise();
		healthbar->Visualise();
		difficultyText->Visualise();
		window->PresentRender();
	}

	//Moves the enemies
	//If any enemy has reached the border, it moves down, otherwise it moves in the direction given
	void Level::MoveEnemies() {
		for (Entity* e : enemies) {
			if ((right && e->GetBounds()->CollidesWith(window->GetRightBounds())) || (!right && e->GetBounds()->CollidesWith(window->GetLeftBounds()))) {
				right=!right;
				for (Entity* enemy : enemies) {
					enemy->Move(Down);
					enemy->Move(Down);
				}
				return;
			}
		}
		for (Entity* enemy : enemies) {
			if (right)
				enemy->Move(Right);
			else
				enemy->Move(Left);
		}
	}

	//Checks if the enemies have reached the bottom
	void Level::CheckIfTargetReached() {
		for (Entity* enemy : enemies) {
			if (enemy->GetBounds()->GetY() + enemy->GetBounds()->GetHeight() > 170) {
				playerShip->Damage(100);
				returnValue = Running;
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
