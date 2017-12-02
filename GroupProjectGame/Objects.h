#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>

class Object {
protected:
	float direction;
	float speed;
	sf::CircleShape* graphic;
	void moveObject();
public:
	Object(float size, float newDirection, float newSpeed);
	void setDirection(float newDirection);
	void setSpeed(float newSpeed);
	bool collision(Object other);
};