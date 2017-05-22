#include "Game.h"
#include "SDLFactory.h"
#include "AbstractFactory.h"
using namespace Game_SDL;
using namespace Game_Core;

int main( int argc, char* argv[] )
{
    AbstractFactory* factory =new SDLFactory();
    Game* game=new Game(factory);
    game->Run();
    delete game;
    delete factory;
    return 0;
}


