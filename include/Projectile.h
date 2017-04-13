#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Entity.h"
class Projectile: public Entity{
    public:
        Projectile(int x, int y, int movementSpeed, InputType direction, int damage);
        ~Projectile();
        void Update();
    private:
        InputType direction;
        int damage;
};
#endif
