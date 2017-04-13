#include "QuadTree.h"
QuadTree::QuadTree(int pLevel, BoundingBox* bounds){
    level=pLevel;
    this->bounds=bounds;
    for(int i=0; i<4; i++)
    	nodes[i]=nullptr;
}
QuadTree::~QuadTree(){
    for(int i=0; i<4; i++)
    {
        delete nodes[i];
    }
}
void QuadTree::Split(){
    int subWidth=(int)(bounds->getWidth()/2);
    int subHeight=(int)(bounds->getHeight()/2);
    int x=(int)bounds->getX();
    int y=(int)bounds->getY();
    nodes[0] = new QuadTree(level+1, new BoundingBox(x + subWidth, y, subWidth, subHeight));
    nodes[1] = new QuadTree(level+1, new BoundingBox(x, y, subWidth, subHeight));
    nodes[2] = new QuadTree(level+1, new BoundingBox(x, y + subHeight, subWidth, subHeight));
    nodes[3] = new QuadTree(level+1, new BoundingBox(x + subWidth, y + subHeight, subWidth, subHeight));
}

//TODO Nakijken
int QuadTree::getIndex(BoundingBox* tbounds){
    int index=-1;
    double verticalMidpoint = bounds->getX() + (bounds->getWidth() / 2);
    double horizontalMidpoint = bounds->getY() + (bounds->getHeight() / 2);

    // Object can completely fit within the top quadrants
    bool topQuadrant = (tbounds->getY() < horizontalMidpoint && tbounds->getY() + tbounds->getHeight() < horizontalMidpoint);
    // Object can completely fit within the bottom quadrants
    bool bottomQuadrant = (tbounds->getY() > horizontalMidpoint);

    // Object can completely fit within the left quadrants
    if (tbounds->getX() < verticalMidpoint && tbounds->getX() + tbounds->getWidth() < verticalMidpoint) {
        if (topQuadrant) {
            index = 1;
        }
        else if (bottomQuadrant) {
            index = 2;
        }
    }
    // Object can completely fit within the right quadrants
    else if (tbounds->getX() > verticalMidpoint) {
        if (topQuadrant) {
            index = 0;
        }
        else if (bottomQuadrant) {
            index = 3;
        }
    }

    return index;
}
int QuadTree::Insert(Entity* entity) {
   // if(level==0 && getIndex(entity->bounds)==-1)
     //   return -1;

	//Lower Level if possible
    if (nodes[0] != nullptr) {
        int index = getIndex(entity->bounds);

        if (index != -1) {
             nodes[index]->Insert(entity);
             return 0;
        }
    }
    //

    //Lowest level achieved, adding entity
    entities.push_back(entity);

    //If level is full, split, and distribute entities
    if (entities.size() > MAX_OBJECTS && level < MAX_LEVELS) {
        if (nodes[0] == nullptr) {
            Split();
        }

        int i = 0;
        while (i < entities.size()) {
            int index = getIndex(entities[i]->bounds);
            if (index != -1) {
                Entity* e=entities[i];
                entities.erase(entities.begin()+i);
                nodes[index]->Insert(e);
            }
            else {
                i++;
            }
        }
    }
    return 0;
}

void QuadTree::Retrieve(std::vector<Entity*>* returnObjects, Entity* entity) {

    int index = getIndex(entity->bounds);
    if (index != -1 && nodes[0] != nullptr) {
        nodes[index]->Retrieve(returnObjects, entity);
    }

    returnObjects->insert(returnObjects->end(), entities.begin(), entities.end());

}
void QuadTree::Clean(){
    if(!entities.empty())
        entities.clear();
    for (int i = 0; i < 4; i++) {
        if (nodes[i] != nullptr) {
            delete nodes[i] ;
            nodes[i]=nullptr;
        }
    }
}
