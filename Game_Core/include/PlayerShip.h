#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <string>
#include "Entity.h"
#include "Window.h"
#include "Timer.h"
#include "Input.h"
#include "AudioEngine.h"
using namespace std;
namespace Game_Core {
class AbstractFactory;
class PlayerShip: public Entity {

    public:
        PlayerShip(AbstractFactory* factory,std::vector<Entity*>* bulletVector, int lives, int x, int y, int movementSpeed);
        virtual ~PlayerShip();
        void Update();
        void Shoot();
        int getLives();
        void Damage(int damage) override;
    protected:
        void Revive();

        int lives;
        Input* inputHandler;
        std::vector<Entity*>* bulletVector;
        AbstractFactory* factory;
        Timer* shootingTimer;
        Timer* invincible;
        AudioEngine* audioEngine;
};}

#endif

