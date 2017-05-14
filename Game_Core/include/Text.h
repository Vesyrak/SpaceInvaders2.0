#ifndef TEXT_H
#define TEXT_H
#include "BoundingBox.h"
#include <string>
namespace Game_Core {

class Text{
public:
	Text(std::string message, int x, int y, int size);
	virtual ~Text();
	virtual void Visualise()=0;
	virtual void Update(std::string message);
	virtual void CenterText(BoundingBox* outerBounds)=0;
	BoundingBox* getBounds();
protected:
	BoundingBox* bounds;
	int size;
	std::string message;
};}
#endif
