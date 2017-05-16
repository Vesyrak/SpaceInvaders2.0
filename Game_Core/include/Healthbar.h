#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include "Entity.h"
#include "Text.h"
namespace Game_Core {
	class AbstractFactory;
	class Healthbar {
		public:
			Healthbar(AbstractFactory* factory, Entity* observed, int x, int y);
			virtual ~Healthbar();
			virtual void Update()=0;
			virtual void Visualise()=0;
		protected:
			BoundingBox* foreBounds;
			BoundingBox* backBounds;
			Text* hpText;
			Entity* observed;
	};
}
#endif
