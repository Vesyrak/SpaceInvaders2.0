#ifndef BASHER_H
#define BASHER_H
#include "Entity.h"
class AbstractFactory;
class Basher: public Entity{
    public:
        Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        ~Basher();
        void Attack();
        void Update();

};
#endif
