#include "Bullet.h"

Bullet::Bullet(int newDirection):Object(5, 5) {
	direction = newDirection;
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setTexture(texture);
}

Bullet::~Bullet() {

}

void Bullet::destroy() {
	delete this;
}

void Bullet::moveObject() {
	float PI = 3.14159;
	float xMove;
	float yMove;
	float radDir = direction * (180 / PI);
	xMove = cos(radDir) * speed;
	yMove = sin(radDir) * speed;
	graphic->move(xMove, yMove);
}