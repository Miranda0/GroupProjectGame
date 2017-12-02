#pragma once
class Player
{
public:
	Player();
	~Player();

	void move(float newX, float newY);
	void shoot();
	void destroy();
};