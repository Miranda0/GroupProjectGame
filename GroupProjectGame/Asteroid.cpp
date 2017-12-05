#include "Asteroid.h"

Asteroid::Asteroid():Object(40, 5) {
	srand (time(NULL));
	int position = rand() % 1280;
	std::cout << "Position: " << position << std::endl;
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setPosition(position, 0);
	graphic->setTexture(texture);
	direction = rand() % 360;
	std::cout << "Direction: " << direction << std::endl;
}

void Asteroid::moveObject(){
	float PI = 3.14159;
	float xMove;
	float yMove;
	float radDir = direction * (180 / PI);
	xMove = cos(radDir) * speed;
	yMove = sin(radDir) * speed;
	graphic->move(xMove, yMove);
}

sf::Sprite* Asteroid::getGraphic() {
	return graphic;
}

Asteroid::~Asteroid() {

}

void Asteroid::destroy() {
	texture.loadFromFile("asteroid-big-0000.png");
	graphic->setTexture(texture);
}