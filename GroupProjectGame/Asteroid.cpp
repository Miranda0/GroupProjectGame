#include "Asteroid.h"

Asteroid::Asteroid():Object(40, 3) {
	srand (time(NULL));
	int position = rand() % 1280;
	std::cout << "Position: " << position << std::endl;
	sf::Texture texture;
	texture.loadFromFile("asteroid.png");
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
	xMove = cos(radDir);
	yMove = sin(radDir);
	graphic->move(xMove, yMove);
}

void runStuff() {
	
}

sf::Sprite* Asteroid::getGraphic() {
	return graphic;
}

