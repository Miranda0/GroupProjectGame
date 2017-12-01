#pragma once 
#include <iostream>
#include <string>

class Objects {
protected:
	float direction;
	float position[2];
	int size;
	float speed;

	void objectCreator();
	void moveObject();
public:

};