#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"
#include "SDLAudioEngine.h"
//SLeep
#include <Windows.h>
#undef CreateWindow //Holy shit windows
#include "QuadTree.h"
#include "Basher.h"
#include "Hivemind.h"
#include "SDLButton.h"
#include "SDLFactory.h"
Game::Game(){
    running=false;
}

Game::~Game(){
	if(factory)
		delete factory;
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
	level=new Level(factory, window,inputHandler);

    running=true;

    Run();
    Stop();
}

void Game::Run(){

    for(int i=0; i<1000; i++)
    {
        Sleep(20);
        level->Update();
        level->Visualise();
    }
    //delete hivemind;

}
void Game::Render(){
    window->PrepareRender();
    background->Visualise();
    level->Visualise();
   // window->Visualise();

    window->PresentRender();
}
void Game::Stop(){
    delete ship;
    delete window;
    cout << "Finished";
}

