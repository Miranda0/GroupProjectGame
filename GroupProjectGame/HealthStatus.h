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
	std::string &getHealthString();
	void buildString();

	void setHealth(int newHealth);
	void setMaxHealth(int newMaxHealth);



private:
	std::string healthString;
	int maxHealth;	
	int health;


};