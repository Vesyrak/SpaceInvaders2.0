#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"

//SLeep
#include <Windows.h>
#undef CreateWindow //Holy shit windows
#include "QuadTree.h"
#include "Basher.h"


Game::Game(){
    running=false;
}

Game::~Game(){
}
bool Game::Initialize(AbstractFactory* factory){
    this->factory=factory;
    window=factory->createWindow(1400, 900);
    window->CreateWindow();
    inputHandler=factory->createInputHandler();
    return true;
}
int Game::Execute(){
    level=new Level();
    level->AddEntity(factory->createBomber(40,40,1));
    running=true;

    Run();
    Stop();
    return 0;
}

void Game::Run(){
    ship =factory->createPlayerShip(40,40, 1);
    level->AddEntity(ship);
    for(int i=0; i<15; i++)
    {
    	Basher* enemy=factory->createBasher(80,80,1);
    	level->AddEntity(enemy);
    }
    for(int i=0; i<1000; i++)
    {
        std::vector<InputType> input=inputHandler->getInput();
        for(InputType n:input){
            cout<<n;
            ship->Move(n);
        }
        Sleep(20);
        level->CheckCollisions();
        Render();
    }

}
void Game::Render(){
    window->PrepareRender();
    ship->Visualise();
    window->PresentRender();
}
void Game::Stop(){
    delete ship;
    delete window;
    cout << "Finished";
}

