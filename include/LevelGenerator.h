#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H
#include "Level.h"
#include "AbstractFactory.h"
class LevelGenerator{
    public:
        Level* Generate(AbstractFactory* factory, int difficulty);

};
#endif
