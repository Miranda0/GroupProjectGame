#pragma once
#include "NPC.h"

class Enemy1 : public NPC // added an identifier 
{
public:
	Enemy1(int newIndentifier);
	~Enemy1();
	void destroy();
private:
	int identifier;
};