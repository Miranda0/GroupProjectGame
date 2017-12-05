#include "Enemy1.h"

// there will be four enemy positions based on the identifier number (to prevent overlap) that will place enemies the nodes will track this I think?
//I am still playing with this idea

Enemy1::Enemy1(int newIdentifier):NPC()
{
	float x = 1200;
	speed = 4;
	radius = 100;
	texture.loadFromFile("enemy1.5.png");
	graphic->setTexture(texture);
	health = 1;
	shoot_speed = 5;
	direction = 3.14159;
	this->identifier = newIdentifier;
	if (identifier == 1)
	{
		float position = rand() % 180;
		graphic->setPosition(x, position);
	}
	else if (identifier == 2)
	{
		float position = (rand() % 180) + 170;
		graphic->setPosition(x, position);
	}
	else if (identifier == 3)
	{
		float position = (rand() % 180) + 340;
		graphic->setPosition(x, position);
	}
	else if (identifier == 4)
	{
		float position = (rand() % 180) + 510;
		graphic->setPosition(x, position);
	}
}


Enemy1::~Enemy1()
{

}

void Enemy1::destroy()
{
	if (destroyed == false) {
		texture.loadFromFile("bubble_explo4.png"); //Miranda editted this line because I couldn't find picture you were trying to open
		graphic->setTexture(texture);
		destroyed = true;
	}
	else {
		// destroy object here after linked list of enemies implemented
	}
}