#include "Window.h"
Window::Window(){
    screen_width=640;
    screen_height=480;
}
Window::Window(int screen_width, int screen_height){
    this->screen_width=screen_width;
    this->screen_height=screen_height;
}
Window::~Window(){
}

