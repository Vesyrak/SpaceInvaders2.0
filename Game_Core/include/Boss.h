#ifndef BOSS_H
#define BOSS_H
#include "Entity.h"
namespace Game_Core {
class Boss: public Entity{
    public:
        Boss(int x, int y, int movementSpeed);
        ~Boss();
        void Update();
};}
#endif
