#ifndef BOMBER_H
#define BOMBER_H
#include "Entity.h"
#include "Timer.h"
class AbstractFactory;
class Bomber: public Entity{
    public:
        Bomber(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        ~Bomber();
        void Attack();
        void Update();
    private:
        AbstractFactory* factory;
        std::vector<Entity*>* bulletVector;
    protected:
        bool charging;
        Timer* timer;
        int difficulty;
};
#endif
