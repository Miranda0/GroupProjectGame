#include "NPC.h"

using std::cout;
using std::endl;

NPC::NPC():Object(40,10)
{
	health = 1;
	shoot_speed = 100;
	direction = 180;
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

float NPC::get_speed()
{
	return this->speed;
}

sf::Sprite* NPC::get_graphic()
{
	return this->graphic;
}

void NPC::movement_pattern()
{

}

void NPC::destroy() {

}