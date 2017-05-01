#include "Game.h"
#include "SDLFactory.h"
#include "AbstractFactory.h"
int main( int argc, char* argv[] )
{
    AbstractFactory* factory =new SDLFactory();
    Game* game=new Game();
    game->Initialize(factory);
    game->Execute();
    delete game;
    delete factory;
    return 0;
}

