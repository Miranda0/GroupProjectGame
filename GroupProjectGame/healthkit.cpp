#include "healthkit.h"
using std::cout;
using std::endl;


healthkit::~healthkit()
{

}

void healthkit::destroy()
{
	texture.loadFromFile("newlifekit.png");
}

healthkit::healthkit():Object(1, 0) {
	srand(time(NULL));
	int position = rand() % 1280;
	std::cout << "Position: " << position << std::endl;
	texture.loadFromFile("newlifekit.png");
	graphic->setPosition(position, 0);
	graphic->setTexture(texture);
	direction = rand() % 360;
	std::cout << "Direction: " << direction << std::endl;
}

sf::Sprite* healthkit::getGraphic()
{
	return graphic;
}

