#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
#include "FileWriter.h"
namespace Game_Core {

Game::Game(AbstractFactory* factory) {
	score = 0;
	lives=3;
	difficulty = 10;
	this->factory = factory;
	window = factory->createWindow(800, 600);
	window->CreateWindow();
	inputHandler = factory->createInputHandler();
	state=Menu;
	username="Fernando";
}

Game::~Game() {
	delete window;
	delete inputHandler;
}

void Game::Run() {
	while(state!=Quit){
		switch(state){
			case Menu:
			{
				Screen* menu = factory->createMenu(window);
				switch(menu->Run()){
					case 1:
						state=Running;
						break;
					case 2:
						state=Quit;//TODO
						break;
					case 3:
						state=Quit;
						break;
				}
				delete menu;
				break;
			}
			case Running:
			{
				Level* level = new Level(factory, window, inputHandler, score, lives, difficulty);
				switch(level->Run()){
					case 1:
						score=level->getScore();
						state=GameOver;
						break;
					case 2:
						lives=level->getRemainingLives();
						score=level->getScore();
						difficulty++;
						state=Running;
						break;
				}
				delete level;
				break;
			}
			case GameOver:
			{
				Screen* screen=factory->createGameOverScreen(score, window);
				switch(screen->Run()){
					case 1:
						state=Menu;
						break;
					case 2:
						FileWriter* writer=new FileWriter();
							writer->updateScore(username, score);
						state=Quit;
						break;
				}
				delete screen;
				break;
			}
		}
	}
}
}
