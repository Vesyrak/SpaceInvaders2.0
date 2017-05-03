#ifndef TEXT_H
#define TEXT_H
#include "BoundingBox.h"
#include <string>
class Text{
public:
	Text(std::string message, int x, int y);
	~Text();
	virtual void Visualise()=0;
	virtual void Update(std::string message);
protected:
	BoundingBox* bounds;
	std::string message;
};
#endif
