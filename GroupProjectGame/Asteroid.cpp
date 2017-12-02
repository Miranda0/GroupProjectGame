#include "Asteroid.h"

Asteroid::Asteroid():Object(40, 3) {
	int position = rand() % 1280;
	
}

void Asteroid::moveObject(){
	float PI = 3.14159;
	float xMove;
	float yMove;
	float radDir = direction * (180 / PI);
	xMove = cos(radDir);
	yMove = sin(radDir);
	graphic->move(xMove, yMove);
}

