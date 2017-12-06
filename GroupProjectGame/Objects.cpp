#include "Objects.h"

Object::Object(float radius, float newSpeed) {
	graphic = new sf::Sprite;
	speed = newSpeed;
	radius = radius;
	destroyed = false;
}

Object::~Object() {
	delete graphic;
}

void Object::setSpeed(float newSpeed) {
	speed = newSpeed;
}

bool Object::collision(Object* other) { // assuming our hitboxes will be circles because easier
	bool crash = false;
	sf::Vector2f xy1 = graphic->getPosition();
	sf::Vector2f xy2 = other->graphic->getPosition();
	float dist1 = xy1.x - xy2.x; //finding distance between points
	float dist2 = xy1.y - xy2.y;
	float num = dist1*dist1 + dist2*dist2;
	float finalDist = pow(num, 0.5);
	if (finalDist <= radius + other->radius) {
		crash = true;
	}
	return crash;
}

bool Object::deleteAtEdge() {
	sf::Vector2f place = graphic->getPosition();
	if (place.x < -50) {
		return true;
		}
	
	if (place.x > 1330) {
		return true;
	}
	else if (place.y < -50) {
		return true;
	}
	else if (place.y > 770) {
		return true;
	}
	return false;
}

sf::RectangleShape Object::getCollisionBox() {
	return collisionBox;
}

bool Object::checkCollision(Collider &other) {
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