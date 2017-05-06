#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
#include "SDLAudioEngine.h"
//SLeep
#include "Basher.h"
#include "SDLButton.h"
#include "SDLFactory.h"
Game::Game(){
    running=false;
    score=0;
}

Game::~Game(){
	if(window)
		delete window;
	if(inputHandler)
		delete inputHandler;
}
bool Game::Initialize(AbstractFactory* factory){
    this->factory=factory;
    window=factory->createWindow(1400, 900);
    window->CreateWindow();
    inputHandler=factory->createInputHandler();
    return true;
}
void Game::Execute(){
	Menu* menu=factory->createMenu(window);
	int selection=menu->Run();
	delete menu;
	switch(selection){
	case 1:
		break;
	case 2:
		break;
	case 3:
		return;
	}

    running=true;

    Run();
    Stop();
}

void Game::Run(){
	level=new Level(factory, window,inputHandler, score, 3);
	level->Run();
	int lives=level->getRemainingLives();
	if(lives<=0){
		return;//todo
	}
	score=level->getScore();
	delete level;
	Run();
}
void Game::Render(){
    window->PrepareRender();
    background->Visualise();
    level->Visualise();
    window->PresentRender();
}
void Game::Stop(){
    delete window;
    cout << "Finished";
}

