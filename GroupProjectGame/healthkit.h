#pragma once
#include "Objects.h"
#include <math.h>
#include "Collider.h"




class healthkit: public Object
{
public:
	

	healthkit();
	~healthkit();
	//int getHealthPts();
	void virtual destroy();
	sf::Sprite* getGraphic();
	Collider getCollision() { return Collider(healthHit);}
	//need to check for collision
	//if collision, add 2 points to health

	



protected:
private:
	int healthPts;
	sf::Texture healthShape;
	int direction;
	sf::RectangleShape healthHit;

};

