#pragma once
#include "NPC.h"

class Enemy1 : public NPC // added an identifier 
{
public:
	Enemy1();
	~Enemy1();
	void destroy();
	bool checkCollision(Collider &other);
	// sf::Sprite &getGraphic();
private:
};