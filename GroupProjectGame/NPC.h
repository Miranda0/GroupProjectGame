#pragma once
#include "Objects.h"

class NPC : protected Object
{
public:
	NPC();
	~NPC();
	void set_graphic(sf::Texture graphic);
	void set_speed(float speed);
	void set_health(int health);
	void set_shoot_speed(float shoot_speed);
	void set_direction(int direction);
	float get_speed();
	sf::Sprite* get_graphic();
	int get_health();
	float get_shoot_speed();
	int get_direction();
	void movement();
	void shoot();
	void virtual destroy();

protected:
	int health;
	float shoot_speed;
	float direction;
};