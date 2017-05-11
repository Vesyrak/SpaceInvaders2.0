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
        PlayerShip(AbstractFactory* factory,std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed);
        virtual ~PlayerShip();
        void Move(InputType dir);
        void Update();
        void Shoot();
        int getLives();
        void Revive();
        void Damage(int damage) override;
    protected:
        int lives;
        Input* inputHandler;
        std::vector<Entity*>* bulletVector;
        AbstractFactory* factory;
        Timer* shootingTimer;
        Timer* invincible;
        AudioEngine* audioEngine;
};}

#endif

