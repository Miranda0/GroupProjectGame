#include "EnemyTrackerNode.h"

EnemyTrackerNode::EnemyTrackerNode()
{
	pNext = nullptr;
	enemy = nullptr;
}

EnemyTrackerNode::~EnemyTrackerNode()
{
	std::cout << "Enemy killed!" << std::endl;
}

void EnemyTrackerNode::set_pNext(EnemyTrackerNode* newNext)
{
	pNext = newNext;
}

void EnemyTrackerNode::set_enemy(NPC* newEnemy)
{
	enemy = newEnemy;
}

NPC* EnemyTrackerNode::get_enemy()
{
	return enemy;
}

EnemyTrackerNode* EnemyTrackerNode::get_pNext()
{
	return pNext;
}
