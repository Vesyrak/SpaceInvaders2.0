#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Entity.h"
namespace Game_Core {
	//Abstract Background
	class Background: public Entity {
		public:
			Background();
			~Background();
	};
}
#endif
