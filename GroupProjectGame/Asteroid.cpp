#include "Asteroid.h"

Asteroid::Asteroid():Object(40, 5) {
	srand (time(NULL));
	int position = rand() % 1280;
	std::cout << "Position: " << position << std::endl;		// debug
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setPosition(position, 0);
	graphic->setTexture(texture);
	direction = rand() % 360;
	std::cout << "Direction: " << direction << std::endl;	// debug
}
Asteroid::Asteroid(float xPos, float yPos, float initSpeed, int initDirection) : Object(0, initSpeed)
{
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setTexture(texture);
	graphic->setPosition(xPos, yPos);
	direction = initDirection;
	collisionBox.setSize(sf::Vector2f(texture.getSize().x - 20.0f, texture.getSize().y-20.0f));
	collisionBox.setPosition(xPos +10, yPos + 10);
	collisionBox.setFillColor(sf::Color::White);
}

void Asteroid::moveObject(){
	float PI = 3.14159;
	float xMove;
	float yMove;
	float radDir = direction * (180 / PI);
	xMove = cos(radDir) * speed;
	yMove = sin(radDir) * speed;
	graphic->move(xMove, yMove);
	collisionBox.move(xMove, yMove);
}

sf::Sprite &Asteroid::getGraphic() {
	return *graphic;
}

Asteroid::~Asteroid() {

}

void Asteroid::destroy() {
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setTexture(texture);
}