#include "BoundingBox.h"
#include <algorithm>
namespace Game_Core {

	BoundingBox::BoundingBox(double x, double y, double width, double height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	BoundingBox::~BoundingBox() {
	}
	double BoundingBox::GetWidth() {
		return width;
	}
	double BoundingBox::GetHeight() {
		return height;
	}
	double BoundingBox::GetX() {
		return x;
	}
	double BoundingBox::GetY() {
		return y;
	}
	void BoundingBox::SetX(double value) {
		x = value;
	}
	void BoundingBox::SetY(double value) {
		y = value;
	}
	void BoundingBox::SetWidth(double value) {
		width = value;
	}
	void BoundingBox::SetHeight(double value) {
		height = value;
	}
	bool BoundingBox::CollidesWith(BoundingBox* bounds) {
		if ((std::max(x, bounds->GetX()) < std::min(x + width, bounds->GetX() + bounds->GetWidth())) && (std::max(y, bounds->GetY()) < std::min(y + height, bounds->GetY() + bounds->GetHeight())))
			return true;
		return false;
	}
}
