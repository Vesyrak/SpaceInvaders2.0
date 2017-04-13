#include <SDL2/SDL.h>
#include <iostream>
#include "Game.h"

//SLeep
#include <Windows.h>
#undef CreateWindow //Holy shit windows
#include "QuadTree.h"
#include "Basher.h"
#include "Hivemind.h"


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
    running=true;

    Run();
    Stop();
    return 0;
}

void Game::Run(){
    ship =factory->createPlayerShip(40,40, 1);
    background=factory->createBackground();
    level->AddEntity(ship);
    Hivemind* hivemind=new Hivemind(1);
    hivemind->Generate(factory,level);
    int count=0;
    for(int i=0; i<1000; i++)
    {
        std::vector<InputType> input=inputHandler->getInput();
        for(InputType n:input){
            cout<<n;
            ship->Move(n);
        }
        if(count==10)
        {
        	count=0;
            hivemind->Update();
        }
        else count++;
        Sleep(20);
        level->CheckCollisions();
        Render();
    }
    delete hivemind;

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

