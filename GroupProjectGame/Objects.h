#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Object {
protected:
	float speed;
	float radius;
	sf::Sprite* graphic;
public:
	Object(float radius, float newSpeed);
	void setSpeed(float newSpeed);
	bool collision(Object other);
};