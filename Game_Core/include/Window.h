#ifndef WINDOW_H
#define WINDOW_H
#include "BoundingBox.h"

namespace Game_Core {

	//The window class, manages visualisation for all things visible.
	class Window {
		public:
			Window();
			Window(int screen_width, int screen_height);
			virtual ~Window();
			virtual int CreateWindow()=0;
			virtual void PrepareRender()=0;
			virtual void PresentRender()=0;
			BoundingBox* GetTopBounds();
			BoundingBox* GetBottomBounds();
			BoundingBox* GetLeftBounds();
			BoundingBox* GetRightBounds();
			const int LOGICAL_WIDTH = 200;
			const int LOGICAL_HEIGHT = 200;
			int screen_width;
			int screen_height;
		protected:
			BoundingBox* topBounds;
			BoundingBox* bottomBounds;
			BoundingBox* leftBounds;
			BoundingBox* rightBounds;
	};
}
#endif
