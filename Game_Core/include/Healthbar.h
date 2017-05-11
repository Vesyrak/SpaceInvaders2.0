#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Entity.h"
#include "Text.h"
namespace Game_Core {

class AbstractFactory;

class Healthbar{
public:
	Healthbar(AbstractFactory* factory, Entity* observed, int x, int y);
	virtual ~Healthbar();
	virtual void Visualise()=0;
	virtual void Update()=0;
protected:
	Entity* observed;
	BoundingBox* foreBounds;
	BoundingBox* backBounds;
	Text* hpText;

};}
#endif
