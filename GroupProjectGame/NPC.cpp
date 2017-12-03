#include "NPC.h"

using std::cout;
using std::endl;

NPC::NPC():Object(0,0)
{
	health = 0;
	shoot_speed = 0;
	direction = 0;
}

NPC::~NPC()
{
	cout << "unit killed" << endl;
}

void NPC::set_graphic(sf::Texture graphic)
{
	this->graphic->setTexture(graphic);
}

void NPC::set_speed(float speed)
{
	this->speed = speed;
}
void NPC::set_health(int health)
{
	this->health = health;
}

void NPC::set_shoot_speed(float shoot_speed)
{
	this->shoot_speed = shoot_speed;
}

void NPC::set_direction(int direction)
{
	this->direction = direction;
}

float NPC::get_speed()
{
	return this->speed;
}

sf::Sprite* NPC::get_graphic()
{
	return this->graphic;
}
int NPC::get_health()
{
	return this->health;
}

float NPC::get_shoot_speed()
{
	return this->shoot_speed;
}

int NPC::get_direction()
{
	return this->direction;
}

void NPC::movement_pattern()
{

}

void NPC::destroy() 
{
	
}

void NPC::shoot()
{

}