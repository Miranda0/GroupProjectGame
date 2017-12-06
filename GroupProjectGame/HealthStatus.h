#include "Objects.h"
#include "Collider.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include<iostream>
#include <ostream>
#include<string>
#include<fstream>


class healthStatus
{
public:
	healthStatus();
	~healthStatus();
	int getHealth();
	int getMaxHealth();

	void setHealth(int newHealth);
	void setMaxHealth(int newMaxHealth);



private:	
	int maxHealth;
	int health;


};