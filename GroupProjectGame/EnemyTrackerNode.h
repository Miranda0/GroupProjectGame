#pragma once
#include "Enemy3.h"
class EnemyTrackerNode
{
public:
	EnemyTrackerNode();
	~EnemyTrackerNode();
	void set_pNext(EnemyTrackerNode* newNext);
	void set_enemy(NPC* newEnemy);
	NPC* get_enemy();
	EnemyTrackerNode* get_pNext();
private:
	NPC* enemy;
	EnemyTrackerNode* pNext;
};