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
		if ((flag & (SPEED_COMPONENT | POSITION_COMPONENT | TIME_COMPONENT | DIRECTION_COMPONENT | STATUS_COMPONENT)) == (SPEED_COMPONENT | POSITION_COMPONENT | TIME_COMPONENT | DIRECTION_COMPONENT | STATUS_COMPONENT))
		{
			ECS::StatusComponent *pStatus = static_cast<ECS::StatusComponent *>(EntityManager::getInstance()->getEntityComponent(STATUS_COMPONENT, i));

			if (pStatus->_status != ECS::StatusComponent::FALL)
				continue;

			ECS::SpeedComponent *pSpeed = static_cast<ECS::SpeedComponent *>(EntityManager::getInstance()->getEntityComponent(SPEED_COMPONENT, i));
			ECS::PositionComponent *pPosition = static_cast<ECS::PositionComponent *>(EntityManager::getInstance()->getEntityComponent(POSITION_COMPONENT, i));
			ECS::TimeComponent *pTime = static_cast<ECS::TimeComponent *>(EntityManager::getInstance()->getEntityComponent(TIME_COMPONENT, i));
			ECS::DirectionComponent *pDirection = static_cast<ECS::DirectionComponent *>(EntityManager::getInstance()->getEntityComponent(DIRECTION_COMPONENT, i));
			if (pTime->_isArrival)
			{
				log("move system time component isArrival:true");
				pDirection->_direction = ECS::DirectionComponent::DOWN;
			}
			
			if (pDirection->_direction == ECS::DirectionComponent::LEFT)
			{
				pPosition->_x -= pSpeed->_speedX;
			}
			else if (pDirection->_direction == ECS::DirectionComponent::RIGHT)
			{
				pPosition->_x += pSpeed->_speedX;
			}
			else if (pDirection->_direction == ECS::DirectionComponent::UP)
			{
				pPosition->_y += pSpeed->_speedY;
			}
			else if (pDirection->_direction == ECS::DirectionComponent::DOWN)
			{
				pPosition->_y -= pSpeed->_speedY;
				log("block down:%f", pPosition->_y);
			}
		}
	}

}

void MoveSystem::exit()
{

}