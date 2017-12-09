#include "Bullet.h"

Bullet::Bullet(int newDirection, float xPos, float yPos):Object(5, 8) {
	direction = newDirection;
	texture.loadFromFile("24581053_10211815882127623_39085008_n.png");
	graphic->setTexture(texture);
	graphic->rotate(90);
	graphic->setPosition(xPos, yPos);
	collisionBox.setPosition(xPos, yPos);
	collisionBox.setSize(sf::Vector2f(10.0f, 10.0f));
	collisionBox.setFillColor(sf::Color::White);
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
	float PI = 3.14159265359;
	float xMove;
	float yMove;
	float radDir = direction * (PI / 180);
	xMove = cos(radDir) * speed;
	yMove = sin(radDir) * speed;
	graphic->move(xMove, yMove);
	collisionBox.move(xMove, yMove);
}