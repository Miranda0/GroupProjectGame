#include "NPC.h"
//#include "Bullet.h"
using std::cout;
using std::endl;

NPC::NPC():Object(20,10)
{
	health = 0;
	shoot_speed = 1;
	direction = 0;
	shot = nullptr;
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

void NPC::movement()
{
	float xMove;
	float yMove;
	float radDir = direction;
	xMove = cos(radDir) * speed;
	yMove = sin(radDir) * speed;
	graphic->move(xMove, yMove);
}

void NPC::destroy() 
{
	
}
// call this everytime move happens in main and it should regulate itself
Bullet* NPC::shoot()
{
	shoot_speed -= 1;
	if (shoot_speed == 0)
	{

		shot = (new Bullet((1.5*3.14159), graphic->getPosition().x + 10, graphic->getPosition().y + 10));
		shoot_speed = 5;
	}
	return shot;
}