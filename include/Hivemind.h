#ifndef HIVEMIND_H
#define HIVEMIND_H
#include "Entity.h"
#include "Level.h"
#include "AbstractFactory.h"
class Hivemind{
    public:
		Hivemind(int difficulty);
        ~Hivemind();
        void Generate(AbstractFactory* factory, Level* level);
        void Update();
    private:
        int level;
        int difficulty;
        const int rows=6;
        const int columns=10;
        Entity **enemyGrid;
        bool right;
};
#endif
