#ifndef GAME_H
#define GAME_H
#include "AbstractFactory.h"
#include "PlayerShip.h"
#include "Input.h"
#include "Level.h"
namespace Game_Core {

enum GameState{ Menu, Running, Paused, GameOver, Quit };
class Game{
    public:
        Game(AbstractFactory* factory);
        void Run();
        ~Game();
    private:
        AbstractFactory* factory;
        Window* window;
        Input* inputHandler;
        int score;
        int difficulty;
        int lives;
        GameState state;
};}
#endif

