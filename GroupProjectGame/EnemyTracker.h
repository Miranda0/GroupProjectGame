#pragma once
#include "EnemyTrackerNode.h"

class EnemyTracker
{
public:
	EnemyTracker();
	~EnemyTracker();

	void insert_front(EnemyTrackerNode* newNode);
	
	//-> definitons

	//int check_enemy1();
	//int check_enemy2();

	bool is_empty();

private:
	EnemyTrackerNode* pHead;
};