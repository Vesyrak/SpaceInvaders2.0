#ifndef BASHER_H
#define BASHER_H
#include "Entity.h"
class Basher: public Entity{
    public:
        Basher(int x, int y, int movementSpeed);
        ~Basher();
        void Attack();
        void Update();
    private:
        int hp;
};
#endif
