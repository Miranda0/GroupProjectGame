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
	/*
		Arthur 12/8/17

	making getGraphic pure virtual so we can also use it to 
	increment time within enemies for enemy movements/ai  
	*/
	sf::Sprite virtual &getGraphic() = 0;
	virtual bool collision(Object* other);
	bool deleteAtEdge();
};