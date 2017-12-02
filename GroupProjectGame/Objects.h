#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Object {
protected:
	float speed;
	float radius;
	sf::Sprite* graphic;
	void virtual destroy() = 0;
public:
	Object(float radius, float newSpeed);
	void setSpeed(float newSpeed);
	virtual bool collision(Object* other);
};