#pragma once
#include "Objects.h"

class NPC : protected Object
{
public:
	NPC();
	~NPC();
	void set_graphic(sf::Texture graphic);
	void set_speed(float speed);
	float get_speed();
	sf::Sprite* get_graphic();
	void movement_pattern();

protected:
	void virtual destroy();
	int health;
	float shoot_speed;
	int direction;
};