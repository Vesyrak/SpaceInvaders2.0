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
        int Execute();
        void Stop();
        ~Game();
    private:
        AbstractFactory* factory;
        void Run();
        void Render();
        bool running;
        PlayerShip* ship;
        Window* window;
        Background* background;
        Input* inputHandler;
        Level* level;
        Overlay* overlay;
};
#endif

