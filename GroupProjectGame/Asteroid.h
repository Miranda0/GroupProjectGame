#pragma once 
#include "Objects.h"
#include <math.h>
#include <cstdlib>

class Asteroid: public Object {
private:
	int direction;
	sf::Texture texture;
public:
	Asteroid();
	~Asteroid();
	void moveObject();
	void virtual destroy();
	sf::Sprite* getGraphic();
};
