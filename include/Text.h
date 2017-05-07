#ifndef TEXT_H
#define TEXT_H
#include "BoundingBox.h"
#include <string>
class Text{
public:
	Text(std::string message, int x, int y, int scaler);
	Text(std::string message, int x, int y);
	virtual ~Text();
	virtual void Visualise()=0;
	virtual void Update(std::string message);
	virtual void CenterText(BoundingBox* outerBounds)=0;
	BoundingBox* bounds;
protected:
	int size;
	std::string message;
};
#endif
