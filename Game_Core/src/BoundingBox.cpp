#include "BoundingBox.h"
#include <algorithm>
namespace Game_Core {

BoundingBox::BoundingBox(double x, double y, double width, double height){
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
}
BoundingBox::~BoundingBox(){
}
double BoundingBox::getWidth(){
    return width;
}
double BoundingBox::getHeight(){
    return height;
}
double BoundingBox::getX(){
    return x;
}
double BoundingBox::getY(){
    return y;
}
void BoundingBox::setX(double value){
    x=value;
}
void BoundingBox::setY(double value){
    y=value;
}
void BoundingBox::setWidth(double value){
    width=value;
}
void BoundingBox::setHeight(double value){
    height=value;
}
bool BoundingBox::collidesWith(BoundingBox* bounds){
	if( (std::max(x, bounds->getX() ) < std::min(x+width, bounds->getX()+bounds->getWidth() )) &&( std::max(y, bounds->getY()) < std::min(y+height, bounds->getY()+bounds->getHeight()) ))
            return true;
    return false;
}
}
