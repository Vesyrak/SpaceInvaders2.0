#ifndef QUADTREE_H
#define QUADTREE_H
#include "BoundingBox.h"
#include "Entity.h"//Todo softcode this
//https://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
class QuadTree{
    private:
        const int MAX_OBJECTS = 10;
        const int MAX_LEVELS = 5;
        int level;
        std::vector<Entity*> entities;
        BoundingBox* bounds;
        QuadTree* nodes[4];
    public:
        QuadTree(int pLevel, BoundingBox* bounds);
        ~QuadTree();
        void Split();
        int getIndex(BoundingBox* tbounds);
        int Insert(Entity* entity);
        void Retrieve(std::vector<Entity*>* returnObjects, Entity* entity);
        void Clean();
};
#endif
