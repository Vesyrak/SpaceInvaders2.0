#include "Text.h"

namespace Game_Core {

	//Constructor sets required parameters
	Text::Text(std::string message, int x, int y, int size) {
		this->message = message;
		bounds = new BoundingBox(x, y, message.size() * 4, 10);
		this->size = size;
	}

	Text::~Text() {
		delete bounds;
	}

	void Text::Update(std::string message) {
		this->message = message;
	}

	BoundingBox* Text::GetBounds() {
		return bounds;
	}
}
