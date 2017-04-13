#include "Level.h"
#include <iostream>
Level::Level(){
    qTree=new QuadTree(0, new BoundingBox(0,0,100,100));
}
Level::~Level(){
    delete qTree;
}
void Level::AddEntity(Entity* entity){
    entities.push_back(entity);
}

void Level::CheckCollisions(){
    qTree->Clean();
    for (int i = 0; i < entities.size(); i++) {
    //    std::cout<<"Inserting: "<< qTree->Insert(entities[i])<<std::endl;
    }
    std::vector<Entity*> returnObjects;
    for (int i = 0; i < entities.size(); i++) {
        returnObjects.clear();
        qTree->Retrieve(&returnObjects, entities[i]);
        std::cout<<returnObjects.size()<<std::endl;
        for (int x = 0; x < returnObjects.size(); x++) {
            // Run collision detection algorithm between objects
        }
    }
}
void Level::Visualise(){
	for(Entity* n:entities){
		n->Visualise();
	}
}

