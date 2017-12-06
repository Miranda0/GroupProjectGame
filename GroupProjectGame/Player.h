#pragma once
#include "Objects.h"
#include "Collider.h"

class Player : public Object
{
public:
	Player();
	~Player();

	int getHealth();

	void move(float newX, float newY);
	void shoot();
	void heal(int healPoints);
	void damage(int damagePoints);
	void destroy();
	void setPosition(float newX, float newY);
	bool isAlive();
	sf::Sprite &getGraphic();
	sf::RectangleShape getCollisionBox();
	Collider getCollision() { return Collider(collisionBox); }
	bool checkCollision(Collider &other);

private:
	sf::Texture playerGraphic;
	sf::RectangleShape collisionBox;
	int playerCurrentHealth;
	int playerMaxHealth;
	bool alive;
};