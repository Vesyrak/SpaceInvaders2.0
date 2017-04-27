#ifndef ENTITY_H
#define ENTITY_H
#include "Window.h"
#include "Input.h"
#include "BoundingBox.h"
class Entity{
    protected:
        int x;
        int y;
        int movementSpeed;
        int hp;
    public:
        Entity(int x, int y, int movementSpeed);
        virtual ~Entity();
        virtual void Move(InputType dir);
        virtual void Visualise()=0;
        virtual void Update()=0;
        int getHP();
        void Damage(int damage);
        BoundingBox* bounds;
};
#endif

