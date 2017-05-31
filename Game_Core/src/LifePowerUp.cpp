#include "LifePowerUp.h"
namespace Game_Core{
	LifePowerUp::LifePowerUp(PlayerShip* playerShip, int x, int y):Entity(x,y,8,8, 2){
		this->playerShip=playerShip;
		this->hp=LifeUp;
	}
	LifePowerUp::~LifePowerUp(){
	}
	void LifePowerUp::Update(){
		Move(Down);
	}
}
