#include "Window.h"

namespace Game_Core {
Window::Window(){
    screen_width=640;
    screen_height=480;
    topBounds=new BoundingBox(0, -10,200, 20);
    bottomBounds=new BoundingBox(0, 200,200, 220);
    leftBounds=new BoundingBox(-10, 0,20, 200);
    rightBounds=new BoundingBox(200, 0,220, 200);
}
Window::Window(int screen_width, int screen_height){
    this->screen_width=screen_width;
    this->screen_height=screen_height;
    topBounds=new BoundingBox(0, -10,200, 10);
        bottomBounds=new BoundingBox(0, 200,200, 210);
        leftBounds=new BoundingBox(-10, 0,10, 200);
        rightBounds=new BoundingBox(200, 0,210, 200);
}
Window::~Window(){
	delete topBounds;
	delete bottomBounds;
	delete leftBounds;
	delete rightBounds;
}
BoundingBox* Window::getTopBounds(){
	return topBounds;
}
BoundingBox* Window::getBottomBounds(){
	return bottomBounds;
}
BoundingBox* Window::getLeftBounds(){
	return leftBounds;
}
BoundingBox* Window::getRightBounds(){
	return rightBounds;
}
}
