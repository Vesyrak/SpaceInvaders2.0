#include "Hivemind.h"

Hivemind::Hivemind(int difficulty){
	this->difficulty=difficulty;
	enemyGrid = new Entity*[rows*columns];
	level=1;
	right=true;
}
Hivemind::~Hivemind(){
	delete enemyGrid;
}
void Hivemind::Generate(AbstractFactory* factory,  std::vector<Entity*> enemies){

	int y=0;
	for (int j=0;j<rows;j++)
	{
		int x=0;
		if(j<2)
			for(int i=0; i<columns; i++){
				Entity* enemy=factory->createBasher(x,y, 2);
				enemyGrid[j*columns+i]=enemy;
				enemies.push_back(enemy);
				x+=15;
			}
		else if(j<4)
			for(int i=0; i<columns; i++){
				Entity* enemy=factory->createBlaster(x,y, 2);
				enemyGrid[j*columns+i]=enemy;
				enemies.push_back(enemy);
				x+=15;
			}
		else
			for(int i=0; i<columns; i++){
				Entity* enemy=factory->createBomber(x,y, 2);
				enemyGrid[j*columns+i]=enemy;
				enemies.push_back(enemy);
				x+=15;
			}
		y+=15;
	}
}

void Hivemind::Update(){
	if(right){
		for( int i=0; i<rows; i++)
		{
			if(enemyGrid[i*columns+9]->bounds->getX()+enemyGrid[i*columns+9]->bounds->getWidth()>200)
			{
				right=false;
				for(int n=0; n<rows*columns; n++){
					if(enemyGrid[n]!=nullptr)
						enemyGrid[n]->Move(Down);
				}
			}
		}
		if(right){
			for(int n=0; n<rows*columns; n++){
				if(enemyGrid[n]!=nullptr)
					enemyGrid[n]->Move(Right);
			}
		}
	}
	else{
		for( int i=0; i<rows; i++)
		{
			if(enemyGrid[i*columns]->bounds->getX()<0)
			{
				right=true;
				for(int n=0; n<rows*columns; n++){
					if(enemyGrid[n]!=nullptr)
						enemyGrid[n]->Move(Down);
				}
			}
		}
		if(!right){
			for(int n=0; n<rows*columns; n++){
				if(enemyGrid[n]!=nullptr)
					enemyGrid[n]->Move(Left);
			}
		}
	}
}

