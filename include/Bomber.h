#ifndef BOMBER_H
#define BOMBER_H
#include "Entity.h"
class Bomber: public Entity{
    public:
        Bomber(int x, int y, int movementSpeed);
        ~Bomber();
        void Attack();
        void Update();
    private:
        int hp;
};
#endif
