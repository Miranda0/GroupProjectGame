#include "Bullet.h"

Bullet::Bullet(int newDirection, float xPos, float yPos):Object(5, 4) {
	direction = newDirection;
	texture.loadFromFile("24581053_10211815882127623_39085008_n.png");
	graphic->setTexture(texture);
	graphic->rotate(90);
	graphic->setPosition(xPos, yPos);
}

Bullet::~Bullet() {

}
void Bullet::destroy() {
	delete this;
}
sf::Sprite &Bullet::getGraphic() {
	return *graphic;
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