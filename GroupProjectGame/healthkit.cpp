#include "healthkit.h"
using std::cout;
using std::endl;

healthkit::healthkit() :Object(10, 0)
{
	srand(time(NULL));
	int position = rand() % 1280;
	texture.loadFromFile("newlifekit.png");
	graphic->setPosition(position, 0);
	graphic->setTexture(texture);
	direction = rand() % 720;
	std::cout << "this worked and the life kit has saved someone" << std::endl;

}

healthkit::~healthkit()
{

}

void healthkit::destroy()
{
	
}



sf::Sprite* healthkit::getGraphic()
{
	return graphic;
}

