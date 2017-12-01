#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>

class Object {
protected:
	float direction;
	float position[2]; // row then column
	int radius; 
	float speed;
	void moveObject();
public:
	void setDirection(float newDirection);
	void setPosition(float newPosition[2]);
	void setRadius(int newRadius);
	void setSpeed(float newSpeed);
	bool collision(Object other);
};