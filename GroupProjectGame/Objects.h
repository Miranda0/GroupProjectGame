#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Object {
protected:
	float speed;
	float radius;
	sf::Sprite* graphic;
	sf::Texture texture;
	void virtual destroy() = 0;
	bool destroyed;
	sf::RectangleShape collisionBox;
public:
	Collider getCollision() { return Collider(collisionBox); }
	sf::RectangleShape getCollisionBox();
	bool checkCollision(Collider &other);
	Object(float radius, float newSpeed);
	~Object();
	void setSpeed(float newSpeed);
	virtual bool collision(Object* other);
	bool deleteAtEdge();
};