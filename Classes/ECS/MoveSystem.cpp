#include "MoveSystem.h"
#include "EntityManager.h"
#include "Component.h"

MoveSystem::MoveSystem(int priority)
{
	this->_priority = priority;
}

MoveSystem::~MoveSystem()
{
}

void MoveSystem::enter()
{

}

void MoveSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();

	for (int i = 0; i < size; ++i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);
		if ((flag & (SPEED_COMPONENT | POSITION_COMPONENT | TIME_COMPONENT)) == (SPEED_COMPONENT | POSITION_COMPONENT | TIME_COMPONENT))
		{
			ECS::SpeedComponent *pSpeed = static_cast<ECS::SpeedComponent *>(EntityManager::getInstance()->getEntityComponent(SPEED_COMPONENT, i));
			ECS::PositionComponent *pPosition = static_cast<ECS::PositionComponent *>(EntityManager::getInstance()->getEntityComponent(POSITION_COMPONENT, i));
			ECS::TimeComponent *pTime = static_cast<ECS::TimeComponent *>(EntityManager::getInstance()->getEntityComponent(TIME_COMPONENT, i));

			if (pTime->_isArrival)
			{
				pPosition->_x += pSpeed->_speedX;
				pPosition->_y += pSpeed->_speedY;
				pTime->_isArrival = false;
			}
			

		}
	}
}

void MoveSystem::exit()
{

}