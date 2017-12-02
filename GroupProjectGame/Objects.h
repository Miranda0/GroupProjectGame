#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Object {
protected:
	float speed;
	sf::Sprite* graphic;
public:
	Object(float size, float newSpeed);
	void setSpeed(float newSpeed);
	bool collision(Object other);
};