#include "EnemyTracker.h"

EnemyTracker::EnemyTracker()
{
	pHead = nullptr;
}
EnemyTracker::~EnemyTracker()
{
	std::cout << "GG" << std::endl;
}

void EnemyTracker::insert_front(EnemyTrackerNode* newNode)
{
	EnemyTrackerNode* pMem = pHead;
	pHead = newNode;
	newNode->set_pNext(pMem);
}

// can't figure out the logic for this atm. Trying to get it to look for an Enemy1 type pointer but I am not exactly sure how to do that 
//Maybe I will need to put a type variable in enemy to return what level of NPC they are?

//int EnemyTracker::check_enemy1()
//{
//	EnemyTrackerNode* pMem = pHead;
//	if (!is_empty())
//	{
//		while (pMem != nullptr)
//		{
//			if (pMem->get_enemy() == Enemy1)
//		}
//	}
//}
//
//int EnemyTracker::check_enemy2()
//{
//	if (!is_empty())
//	{
//
//	}
//}

bool EnemyTracker::is_empty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}