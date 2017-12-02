#pragma once 
#include "Objects.h"
#include <math.h>
#include <cstdlib>

class Asteroid: public Object {
private:
	float direction;
public:
	Asteroid();
	void moveObject();
	void blowUp();
	void runStuff();
	sf::CircleShape* getGraphic();
};
