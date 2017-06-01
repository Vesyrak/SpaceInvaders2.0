#ifndef TEXT_H
#define TEXT_H
#include "BoundingBox.h"
#include <string>

namespace Game_Core {

	//Base visualiser for text
	class Text {
		public:
			Text(std::string message, int x, int y, int size);
			virtual ~Text();
			virtual void Update(std::string message);
			virtual void Visualise()=0;
			virtual void CenterText(BoundingBox* outerBounds)=0;
			virtual void HorizontalCenterText(int x, int width)=0;
			virtual void VerticalCenterText(int y, int height)=0;
			BoundingBox* GetBounds();
		protected:
			BoundingBox* bounds;
			std::string message;
			int size;
	};
}
#endif
