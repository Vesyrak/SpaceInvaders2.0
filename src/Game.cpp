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
    level=new Level(factory, window,inputHandler);
    running=true;

    Run();
    Stop();
    return 0;
}

void Game::Run(){
    int count=0;
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
    overlay->Visualise();
    window->PresentRender();
}
void Game::Stop(){
    delete ship;
    delete window;
    cout << "Finished";
}

