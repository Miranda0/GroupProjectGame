#include "Enemy1.h"

// there will be four enemy positions based on the identifier number (to prevent overlap) that will place enemies the nodes will track this I think?
//I am still playing with this idea

Enemy1::Enemy1():NPC()
{
	float x = 1200;
	speed = 3;
	radius = 50;
	texture.loadFromFile("enemy1.5.png");
	graphic->setTexture(texture);
	health = 1;
	shoot_speed = 5;
	direction = 3.14159 * .5;
	float position = rand() % 1280;
	graphic->setPosition(position, 0);
	this->collisionBox.setPosition(position + 50, 10);
}
Enemy1::~Enemy1()
{

}

//sf::Sprite &Enemy1::getGraphic()
//{
//	return this->getGraphic();
//}
void Enemy1::destroy()
{
	if (destroyed == false) {
		texture.loadFromFile("bubble_explo4.png"); //Miranda editted this line because I couldn't find picture you were trying to open
		graphic->setTexture(texture);
		destroyed = true;
	}
	else {
		// destroy object here after linked list of enemies implemented
	}
}

bool Enemy1::checkCollision(Collider &other) {
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = collisionBox.getPosition();
	sf::Vector2f thisHalfSize = collisionBox.getSize() / 2.0f;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		return true;
	}
	return false;
}