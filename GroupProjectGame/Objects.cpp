#include "Objects.h"

Object::Object(float size, float newDirection, float newSpeed) {
	graphic = new sf::CircleShape(size);
	direction = newDirection;
	speed = newSpeed;
}

void Object::moveObject() {
	
}

void Object::setDirection(float newDirection) {
	direction = newDirection;
}

void Object::setSpeed(float newSpeed) {
	speed = newSpeed;
}

bool Object::collision(Object other) { // assuming our hitboxes will be circles because easier
	bool crash = false;
	float dist1 = graphic->getPosition[1] - other.graphic->getPosition[1]; //finding distance between points
	float dist2 = graphic->getPosition[2] - other.graphic->getPosition[2];
	float num = dist1*dist1 + dist2*dist2;
	float finalDist = pow(num, 0.5);
	if (finalDist <= graphic->getRadius + other.graphic->getRadius) {
		crash = true;
	}
	return crash;
}