#pragma once 
#include "Objects.h"
#include <math.h>
#include <cstdlib>

class Asteroid: public Object {
private:
	int direction;
public:
	Asteroid();
	~Asteroid();
	void moveObject();
	void destroy();
	void virtual destroy();
	sf::Sprite* getGraphic();
};
