#ifndef BLASTER_H
#define BLASTER_H
#include "Entity.h"
class Blaster: public Entity{
    public:
        Blaster(int x, int y, int movementSpeed);
        ~Blaster();
        void Update();
};
#endif
