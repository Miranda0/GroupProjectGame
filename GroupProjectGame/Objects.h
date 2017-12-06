#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Object {
protected:
	float speed;
	float radius;
	sf::Sprite* graphic;
	sf::Texture texture;
	void virtual destroy() = 0;
	bool destroyed;
public:
	Object(float radius, float newSpeed);
	~Object();
	void setSpeed(float newSpeed);
	virtual bool collision(Object* other);
	bool deleteAtEdge();
};