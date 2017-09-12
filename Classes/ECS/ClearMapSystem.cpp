#include "ClearMapSystem.h"
#include "GameInfo.h"

ClearMapSystem::ClearMapSystem(int priority)
{
	this->_priority = priority;
}

ClearMapSystem::~ClearMapSystem()
{

}

void ClearMapSystem::enter()
{

}

void ClearMapSystem::excute(float dt)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (GameInfo::getInstance()->getBlock(i, j) == MOVEING_BLOCK)
			{
				GameInfo::getInstance()->setBlock(i, j, NULL_BLOCK);
			}
		}
	}
}

void ClearMapSystem::exit()
{

}