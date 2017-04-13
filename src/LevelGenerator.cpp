#include "LevelGenerator.h"
#include <stdlib.h>
#include <time.h>

Level* LevelGenerator::Generate(AbstractFactory* factory,int difficulty){
    srand(time(NULL));
    int enemyCount=rand()%(5*difficulty)+10;
    int enemyType[3];
    std::vector<Entity*> enemies;
    for(int i=0; i<enemyCount; i++){
        enemyType[rand()%3]+=1;
    }
    for(int i=0; i<enemyType[0]; i++){
  //      enemies.push_back(factory->createBasher());
    }
    for(int i=0; i<enemyType[1]; i++){
 //       enemies.push_back(factory->createBlaster());
    }
    for(int i=0; i<enemyType[2]; i++){
//        enemies.push_back(factory->createBomber());
    }
    return new Level();

}

