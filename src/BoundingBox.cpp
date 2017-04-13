#include "BoundingBox.h"
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
