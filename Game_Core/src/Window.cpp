#include "Window.h"

namespace Game_Core {

	//Standard Constructor to call the other one with standard parameters
	Window::Window():Window(640,480){
	}

	Window::Window(int screen_width, int screen_height) {
		this->screen_width = screen_width;
		this->screen_height = screen_height;
		topBounds = new BoundingBox(0, -10, 200, 10);
		bottomBounds = new BoundingBox(0, 200, 200, 210);
		leftBounds = new BoundingBox(-10, 0, 10, 200);
		rightBounds = new BoundingBox(200, 0, 210, 200);
	}

	Window::~Window() {
		delete topBounds;
		delete bottomBounds;
		delete leftBounds;
		delete rightBounds;
	}

	BoundingBox* Window::GetTopBounds() {
		return topBounds;
	}

	BoundingBox* Window::GetBottomBounds() {
		return bottomBounds;
	}

	BoundingBox* Window::GetLeftBounds() {
		return leftBounds;
	}

	BoundingBox* Window::GetRightBounds() {
		return rightBounds;
	}
}
