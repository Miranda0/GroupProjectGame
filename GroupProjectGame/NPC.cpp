#include "NPC.h"

using std::cout;
using std::endl;

NPC_1::NPC_1():Object(40,10)
{
	health = 1;
	shoot_speed = 100;
	direction = 180;
}

NPC_1::~NPC_1()
{
	cout << "unit killed" << endl;
}

void NPC_1::set_graphic(sf::Texture* graphic)
{
	this->graphic->setTexture(graphic);
}

void NPC_1::set_speed(float speed)
{
	this->speed = speed;
}

float NPC_1::get_speed()
{
	return this->speed;
}

sf::CircleShape* NPC_1::get_graphic()
{
	return this->graphic;
}

void NPC_1::movement_pattern()
{

}
