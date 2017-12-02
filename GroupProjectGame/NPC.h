#pragma once
#include "Objects.h"

class NPC_1 : protected Object
{
public:
	NPC_1();
	~NPC_1();
	void set_graphic(sf::CircleShape* graphic);
	void set_speed(float speed);
	float get_speed();
	sf::CircleShape* get_graphic();
	void movement_pattern();

private:
	int health;
	float shoot_speed;
};