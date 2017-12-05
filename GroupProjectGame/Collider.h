#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape collisionBox);
	~Collider();

	bool checkCollision(Collider &other);
	sf::Vector2f getPosition() { return body.getPosition(); }
	sf::Vector2f getHalfSize() { return body.getSize() / 2.0f; }
private:
	sf::RectangleShape body;
};