#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
#include "FileWriter.h"
#include "Level.h"
#include "AbstractFactory.h"

namespace Game_Core {

	//Constructor sets required parameters, state and default name
	Game::Game(AbstractFactory* factory) {
		score = 0;
		lives = 3;
		difficulty = 1;
		this->factory = factory;
		window = factory->CreateWindow(1366, 726);
		window->CreateWindow();
		state = Menu;
		username = "Fernando";
	}

	Game::~Game() {
		delete window;
	}

	//Core game loop, keeps running until the state is set on "QuitGame"
	void Game::Run() {
		while (state != QuitGame) {
			switch (state) {
				//Main menu screen.
				case Menu: {
					Screen* menu = factory->CreateMenu(window);
					switch (menu->Run()) {
						case QuitGame:
							state = QuitGame;
							break;
						case NextLevel:
							state = NextLevel;
							break;
						case Settings:
							state = Settings;
							break;
					}
					delete menu;
					break;
				}
				case Settings: {
					Screen* menu = factory->CreateSettingsScreen(window, &username);
					switch (menu->Run()) {
						case QuitGame:
							state = QuitGame;
							break;
						case Menu:
							state = Menu;
							break;
					}
					delete menu;
					break;
				}
				case NextLevel: {
					Screen* screen = factory->CreateNextLevelScreen(difficulty, window);
					switch (screen->Run()) {
						case QuitGame:
							state = QuitGame;
							break;
						case Running:
							state = Running;
							break;
					}
					delete screen;
					break;
				}
				case Running: {
					Level* level = new Level(factory, window, score, lives, difficulty);
					switch (level->Run()) {
						case QuitGame:
							state = QuitGame;
							break;
						case GameOver:
							score = level->GetScore();
							state = GameOver;
							break;
						case NextLevel:
							lives = level->GetRemainingLives();
							score = level->GetScore();
							difficulty++;
							state = NextLevel;
							break;
						case Running:
							lives = level->GetRemainingLives();
							score = level->GetScore();
							state = Running;
							break;
					}
					delete level;
					break;
				}
				case GameOver: {
					FileWriter writer;
					writer.UpdateScore(username, score);
					Screen* screen = factory->CreateGameOverScreen(username, score, window);
					score = 0;
					difficulty = 1;
					lives = 3;
					switch (screen->Run()) {
						case QuitGame:
							state = QuitGame;
							break;
						case Menu:
							state = Menu;
							break;
					}
					delete screen;
					break;
				}
			}
		}
	}
}
