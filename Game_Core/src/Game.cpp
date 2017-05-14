#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
#include "FileWriter.h"
namespace Game_Core {

Game::Game(AbstractFactory* factory) {
	score = 0;
	lives = 3;
	difficulty = 1;
	this->factory = factory;
	window = factory->createWindow(800, 600);
	window->CreateWindow();
	state = Menu;
	username = "Fernando";
}

Game::~Game() {
	delete window;
}

void Game::Run() {
	while (state != Quit) {
		switch (state) {
			case Menu: {
				Screen* menu = factory->createMenu(window);
				switch (menu->Run()) {
					case 1:
						state = NextLevel;
						break;
					case 2:
						state = Settings;
						break;
					case 3:
						state = Quit;
						break;
				}
				delete menu;
				break;
			}
			case Settings: {
				Screen* menu = factory->createSettingsScreen(window, &username);
				switch (menu->Run()) {
					case 1:
						state = Menu;
						break;
				}
				delete menu;
				break;
			}
			case NextLevel:{
				Screen* screen=factory->createNextLevelScreen(difficulty, window);
				switch(screen->Run()){
					case 1:
						state=Running;
						break;
				}
				delete screen;
				break;
			}
			case Running: {
				Level* level = new Level(factory, window, score, lives, difficulty);
				switch (level->Run()) {
					case 1:
						score = level->getScore();
						state = GameOver;
						break;
					case 2:
						lives = level->getRemainingLives();
						score = level->getScore();
						difficulty++;
						state = NextLevel;
						break;
					case 3:
						lives = level->getRemainingLives();
						score = level->getScore();
						state = Running;
						break;
				}
				delete level;
				break;
			}
			case GameOver: {
				FileWriter writer;
				writer.updateScore(username, score);
				Screen* screen = factory->createGameOverScreen(username, score, window);
				score = 0;
				difficulty = 1;
				lives = 3;
				switch (screen->Run()) {
					case 1:
						state = Menu;
						break;
					case 2:

						state = Quit;
						break;
				}
				delete screen;
				break;
			}
		}
	}
}
}
