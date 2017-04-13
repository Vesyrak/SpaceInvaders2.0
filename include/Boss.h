#ifndef BOSS_H
#define BOSS_H
#include "Entity.h"
class Boss: public Entity{
    public:
        Boss(int x, int y, int movementSpeed);
        ~Boss();
        void Update();
};
#endif
