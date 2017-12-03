#pragma once
#include "Objects.h"
#include <math.h>




class healthkit: public Object
{
public:
	

	healthkit();
	~healthkit();
	//int getHealthPts();
	void virtual destroy();
	sf::Sprite* getGraphic();

	



protected:
private:
	//int healthPts;
	sf::Texture texture;
	int direction;

};