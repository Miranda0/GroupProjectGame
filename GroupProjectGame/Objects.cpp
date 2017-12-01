#include "Objects.h"

void Object::moveObject() {
	
}

void Object::setDirection(float newDirection) {
	direction = newDirection;
}

void Object::setPosition(float newPosition[2]) {
	position[1] = newPosition[1];
	position[2] = newPosition[2];
}

void Object::setRadius(int newRadius) { // shouldn't change after initialization
	radius = newRadius;
}

void Object::setSpeed(float newSpeed) {
	speed = newSpeed;
}

bool Object::collision(Object other) { // assuming our hitboxes will be circles because easier
	bool crash = false;
	float dist1 = position[1] - other.position[1]; //finding distance between points
	float dist2 = position[2] - other.position[2];
	float num = dist1*dist1 + dist2*dist2;
	float finalDist = pow(num, 0.5);
	if (finalDist <= radius + other.radius) {
		crash = true;
	}
	return crash;
}