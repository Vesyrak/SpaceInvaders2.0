#ifndef BLASTER_H
#define BLASTER_H
#include "Entity.h"
#include "AudioEngine.h"
class AbstractFactory;
class Blaster: public Entity{
    public:
        Blaster(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        ~Blaster();
        void Attack();
        void Update();
        void Damage(int damage);
    private:
        AbstractFactory* factory;
        std::vector<Entity*>* bulletVector;
        int difficulty;
        AudioEngine* audioEngine;
};
#endif
