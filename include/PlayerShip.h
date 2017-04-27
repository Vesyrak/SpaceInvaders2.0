#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <string>
#include "Entity.h"
#include "Window.h"
#include "Input.h"
using namespace std;
class AbstractFactory;
class PlayerShip: public Entity {

    public:
        PlayerShip(AbstractFactory* factory,std::vector<Entity*>* bulletVector,Input* input, int x, int y, int movementSpeed);
        virtual ~PlayerShip();
        void Move(InputType dir);
        void Update();
        void Shoot();
    private:
        int lives;
        Input* inputHandler;
        std::vector<Entity*>* bulletVector;
        AbstractFactory* factory;
};
#endif

