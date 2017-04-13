#include "Boss.h"

Boss::Boss(int x, int y, int movementSpeed): Entity(x, y, movementSpeed){
    bounds=new BoundingBox(x,y,20,20);
}
Boss::~Boss(){
}
void Boss::Update(){
}

