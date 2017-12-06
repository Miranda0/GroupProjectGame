#include "HealthStatus.h"
using std::cout;
using std::endl;

healthStatus::healthStatus()
{
	int currentHealth = int(this->getHealth()) / (int(this->getMaxHealth()) / 20);
	int lostHealth = 20 - currentHealth;

	cout << "Health: ";
	for (int i = 0; i < currentHealth; i++)
	{
		cout << '*';
	}
	for (int i = 0; i < lostHealth; i++)
	{
		cout << '-';
	}
	cout << endl;
	buildString();
}
	
	
	healthStatus::~healthStatus()
	{

	}

	
	int healthStatus::getHealth()
	{
		return health;
	}
	int healthStatus::getMaxHealth()
	{
		return maxHealth;
	}
	std::string &healthStatus::getHealthString() {
		return healthString;
	}
	void healthStatus::buildString() {
		healthString = "";
		for (int i = 0; i < health; i++)
			healthString.append("*");
		for (int i = 0; i < (maxHealth - health); i++)
			healthString.append("-");
	}

	void healthStatus::setHealth(int newHealth)
	{
		health = newHealth;
		buildString();
	}
	void healthStatus::setMaxHealth(int newMaxHealth)
	{
		maxHealth = newMaxHealth;
		buildString();
	}

	

	

	