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

//need to set points to 2 for health kit, and collisions


sf::Sprite* healthkit::getGraphic()
{
	return graphic;
}

void collisionDetect()
{
	
}



//health kit ptr != ptr
//line 75 - 80 in main point to ptr