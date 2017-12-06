#pragma once 
#include "Objects.h"
#include "Collider.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>

class Asteroid: public Object {
private:
	int direction;
	
public:
	Asteroid();
	Asteroid(float xPos, float yPos, float speed = 1.0f, int direction = 0);
	~Asteroid();
	void moveObject();
	void virtual destroy();
	sf::Sprite* getGraphic();
};
