#include "Enemy1.h"

Enemy1::Enemy1()
{
	speed = 4;
	texture.loadFromFile("enemy1.png");
	graphic->setTexture(texture);
	health = 1;
	shoot_speed = 5;
	direction = 180;
}


Enemy1::~Enemy1()
{

}

void Enemy1::destroy()
{

}