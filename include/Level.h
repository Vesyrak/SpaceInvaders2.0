#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include <list>
#include "QuadTree.h"
class Level{
    public:
        Level();
        ~Level();
        void AddEntity(Entity* entity);
        void CheckCollisions();
    private:
        QuadTree* qTree;
        std::vector<Entity*> entities;
        void CheckBounds();

};
#endif
