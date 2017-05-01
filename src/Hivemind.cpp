#include "Hivemind.h"

Hivemind::Hivemind(int difficulty) :
		enemyContainer(rows, std::vector<Entity*>(columns, 0)) {
	this->difficulty = difficulty;
	level = 1;
	right = true;
	std::vector<std::vector<int>> v(10, std::vector<int>(5));

}
Hivemind::~Hivemind() {
	//delete enemyGrid;
}
void Hivemind::Generate(AbstractFactory* factory,
		std::vector<Entity*>* enemies) {

	int y = 0;
	for (int j = 0; j < rows; j++) {
		int x = 0;
		if (j < 2)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBasher(x, y, 2);
				enemyContainer[j][i] = enemy;
				enemies->push_back(enemy);
				x += 15;
			}
		else if (j < 4)
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBlaster(x, y, 2);
				enemyContainer[j][i] = enemy;
				enemies->push_back(enemy);
				x += 15;
			}
		else
			for (int i = 0; i < columns; i++) {
				Entity* enemy = factory->createBomber(x, y, 2);
				enemyContainer[j][i] = enemy;
				enemies->push_back(enemy);
				x += 15;
			}
		y += 15;
	}
}

void Hivemind::Update() {
	if (right) {
		for (int i = 0; i < rows; i++) {
			Entity* e = enemyContainer[i].back();
			if (e->bounds->getX() + e->bounds->getWidth() > 200) {
				right = false;
				for (int n = 0; n < columns; n++) {
					for (int m = 0; m < rows; m++) {

						if (enemyContainer[m][n] != nullptr)
							enemyContainer[m][n]->Move(Down);
					}
				}
			}
		}
		if (right) {
			for (int n = 0; n < columns; n++) {
				for (int m = 0; m < rows; m++) {

					if (enemyContainer[m][n] != nullptr)
						enemyContainer[m][n]->Move(Right);
				}
			}
		}
	} else {
		for (int i = 0; i < rows; i++) {
			if (enemyContainer[i][0]->bounds->getX() < 0) {
				right = true;
				for (int n = 0; n < columns; n++) {
					for (int m = 0; m < rows; m++) {

						if (enemyContainer[m][n] != nullptr)
							enemyContainer[m][n]->Move(Down);
					}
				}
			}
		}
		if (!right) {
			for (int n = 0; n < columns; n++) {
				for (int m = 0; m < rows; m++) {

					if (enemyContainer[m][n] != nullptr)
						enemyContainer[m][n]->Move(Left);
				}
			}
		}
	}
}

