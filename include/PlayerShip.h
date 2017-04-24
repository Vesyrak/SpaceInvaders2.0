#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <string>
#include "Entity.h"
#include "Window.h"
using namespace std;

class PlayerShip: public Entity {

    public:
        PlayerShip(int x, int y, int movementSpeed);
        virtual ~PlayerShip();
        void Move(InputType dir);
        void Update();
        void Shoot();
    private:
        int lives;
        int hp;
};
#endif

