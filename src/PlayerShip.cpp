#include "PlayerShip.h"
#include <iostream>
PlayerShip::PlayerShip(int x, int y, int movementSpeed):Entity(x,y,movementSpeed){
    bounds=new BoundingBox(x, y, 8,8);
}
PlayerShip::~PlayerShip(){
}
void PlayerShip::Move(InputType dir){
    if(dir==InputType::Up || dir==InputType::Down)
        dir=InputType::None;
    Entity::Move(dir);
}
void PlayerShip::Update(){
}

void PlayerShip::Shoot(){

}
