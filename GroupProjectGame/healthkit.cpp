#include "healthkit.h"
using std::cout;
using std::endl;

healthkit::healthkit() :Object(10, 0)
{
	srand(time(NULL));
	healthShape.loadFromFile("newlifekit.png");
	graphic->setTexture(healthShape);
	healthKit.setSize(sf::Vector2f(20.0f, 20.0f));
	

	int position = 600;
	graphic->setPosition(position, 240);
	
	std::cout << "this worked and the life kit has saved someone" << std::endl;

	

}

healthkit::~healthkit()
{



}


void healthkit::destroy()
{
	//this means I've hit the healthkit and a heart should appear
	healthShape.loadFromFile("green-heart-smiley-1F49A.png");
	graphic->setTexture(healthShape);

	//need to set points to 2 for health kit, and collisions
}

sf::Sprite &healthkit::getGraphic()
{
	return *graphic;
}

void collisionDetect() 
{
	
}



//health kit ptr != ptr
//line 75 - 80 in main point to ptr