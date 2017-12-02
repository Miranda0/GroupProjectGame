#include "Objects.h"

Object::Object(float size, float newDirection, float newSpeed) {
	graphic = new sf::CircleShape(size);
	speed = newSpeed;
}


void Object::setSpeed(float newSpeed) {
	speed = newSpeed;
}

bool Object::collision(Object other) { // assuming our hitboxes will be circles because easier
	bool crash = false;
	sf::Vector2f xy1 = graphic->getPosition();
	sf::Vector2f xy2 = other.graphic->getPosition();
	float dist1 = xy1.x - xy2.x; //finding distance between points
	float dist2 = xy1.y - xy2.y;
	float num = dist1*dist1 + dist2*dist2;
	float finalDist = pow(num, 0.5);
	if (finalDist <= graphic->getRadius() + other.graphic->getRadius()) {
		crash = true;
	}
	return crash;
}