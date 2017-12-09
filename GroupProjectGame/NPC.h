#pragma once
#include "Objects.h"
#include "Bullet.h"
class NPC : public Object  //Miranda editted this because I couldn't access functions in object
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
	sf::Sprite &getGraphic();
	int get_health();
	float get_shoot_speed();
	int get_direction();
	void movement();
	Bullet* shoot();
	void virtual destroy();

protected:
	int time;
	int health;
	float shoot_speed;
	float direction;
	Bullet* shot; // why isn't this a bullet?
};