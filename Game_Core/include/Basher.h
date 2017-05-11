#ifndef BASHER_H
#define BASHER_H
#include "Entity.h"
#include "AudioEngine.h"
namespace Game_Core {
class AbstractFactory;
class Basher: public Entity{
    public:
        Basher(AbstractFactory* factory, std::vector<Entity*>* bulletVector,int x, int y, int difficulty);
        ~Basher();
        void Attack();
        void Update();
        void Damage(int damage);
    private:
        AudioEngine* audioEngine;
};
}
#endif
