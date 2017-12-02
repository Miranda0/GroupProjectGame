#include "Asteroid.h"

Asteroid::Asteroid():Object(40, 3) {
	srand (time(NULL));
	int position = rand() % 1280;
	std::cout << "Position: " << position << std::endl;
	graphic->setPosition(position, 0);
	graphic->setFillColor(sf::Color::Blue);
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

sf::CircleShape* Asteroid::getGraphic() {
	return graphic;
}

