#pragma once
#include "Objects.h"

class NPC_1 : protected Object
{
public:
	NPC_1();
	~NPC_1();
	void set_graphic(sf::Texture graphic);
	void set_speed(float speed);
	float get_speed();
	sf::Sprite* get_graphic();
	void movement_pattern();

protected:
	int health;
	float shoot_speed;
	int direction;
};