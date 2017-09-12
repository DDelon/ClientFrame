#include "RemoveSystem.h"
#include "GameInfo.h"

RemoveSystem::RemoveSystem()
{

}

RemoveSystem::~RemoveSystem()
{

}

void RemoveSystem::enter()
{

}

void RemoveSystem::excute(float dt)
{
	auto isFullRow = [=](int row)->bool{
		for (int j = 0; j < COL; ++j)
		{
			if (GameInfo::getInstance()->getBlock(row, j) != FULL_BLOCK)
			{
				return false;
			}
		}

		return true;
	};

	for (int i = 0; i < ROW; ++i)
	{
		if (isFullRow(i))
		{
			//remove row
		}
	}
}

void RemoveSystem::exit()
{

}