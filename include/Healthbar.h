#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Entity.h"
class Healthbar{
public:
	Healthbar(Entity* observed, int x, int y);
	~Healthbar();
	virtual void Visualise()=0;
	virtual void Update()=0;
protected:
	Entity* observed;
	BoundingBox* foreBounds;
	BoundingBox* backBounds;
};
#endif
