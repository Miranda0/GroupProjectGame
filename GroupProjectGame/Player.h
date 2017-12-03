#pragma once
#include "Objects.h"

class Player : public Object
{
public:
	Player();
	~Player();

	void move(float newX, float newY);
	void shoot();
	void destroy();
	void setPosition(float newX, float newY);
	bool isAlive();
	sf::Sprite &getGraphic();
	

private:
	sf::Texture playerGraphic;
	int playerHealth;
	bool alive;
};