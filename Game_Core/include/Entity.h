#ifndef ENTITY_H
#define ENTITY_H
#include "Window.h"
#include "Input.h"
#include "BoundingBox.h"
namespace Game_Core {
class Entity{
    protected:
        int movementSpeed;
        int hp;
    public:
        Entity(int x, int y, int width, int height,int movementSpeed);
        virtual ~Entity();
        virtual void Move(InputType dir);
        virtual void Visualise()=0;
        virtual void Update()=0;
        int getHP();
        virtual void Damage(int damage);
        BoundingBox* bounds;
};}
#endif

