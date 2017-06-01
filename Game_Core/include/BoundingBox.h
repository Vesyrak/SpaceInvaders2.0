#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

namespace Game_Core {

	//Fundamental class defining the bounds/collision rectangles of just about everything
	class BoundingBox {
		public:
			BoundingBox(double x, double y, double width, double height);
			~BoundingBox();
			double GetWidth();
			double GetHeight();
			double GetX();
			double GetY();
			void SetX(double value);
			void SetY(double value);
			void SetWidth(double value);
			void SetHeight(double value);
			bool CollidesWith(BoundingBox* bounds);
		private:
			double x;
			double y;
			double width;
			double height;
	};
}
#endif
