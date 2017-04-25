#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <string>
#include "Entity.h"
#include "Window.h"
#include "Input.h"
using namespace std;

class PlayerShip: public Entity {

    public:
        PlayerShip(std::vector<Entity*> bulletVector,Input* input, int x, int y, int movementSpeed);
        virtual ~PlayerShip();
        void Move(InputType dir);
        void Update();
        void Shoot();
    private:
        int lives;
        int hp;
        Input* inputHandler;
        std::vector<Entity*> bulletVector;
};
#endif

