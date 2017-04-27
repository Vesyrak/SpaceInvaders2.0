#include "Background.h"

Background::Background() :
		Entity(0, 0, 0) {
	bounds = new BoundingBox(0, 0, 200, 200);
}
Background::~Background() {
}

