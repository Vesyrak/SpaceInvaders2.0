#ifndef BLASTER_H
#define BLASTER_H
#include "Entity.h"
class AbstractFactory;
class Blaster: public Entity{
    public:
        Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int movementSpeed);
        ~Blaster();
        void Attack();
        void Update();
    private:
        AbstractFactory* factory;
        std::vector<Entity*>* bulletVector;
};
#endif
