#ifndef GAME_H
#define GAME_H
#include "AbstractFactory.h"
#include "PlayerShip.h"
#include "Input.h"
#include "Level.h"
class Game{
    public:
        Game();
        bool Initialize(AbstractFactory* factory);
        void Execute();
        void Stop();
        ~Game();
    private:
        AbstractFactory* factory;
        void Run();
        void Render();
        void DetectCollisions(std::vector<Entity> l1, std::vector<Entity> l2);
        bool running;
        Window* window;
        Input* inputHandler;
        Level* level;
        int score;
        int difficulty;

};
#endif

