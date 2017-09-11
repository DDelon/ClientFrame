#include "InputSystem.h"
#include "Component.h"
#include "GameInfo.h"
#include "EntityManager.h"

InputSystem::InputSystem(int priority)
{
	this->_priority = priority;
}

InputSystem::~InputSystem()
{

}

void InputSystem::enter()
{

}

void InputSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();
	int keyCode = GameInfo::getInstance()->getKeyCode();

	for (int i = 0; i < size; ++i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);
		if ((flag & DIRECTION_COMPONENT) == DIRECTION_COMPONENT)
		{
			ECS::DirectionComponent *pDirection = static_cast<ECS::DirectionComponent *>(EntityManager::getInstance()->getEntityComponent(DIRECTION_COMPONENT, i));
			if (keyCode == ECS::DirectionComponent::UP)
			{
				pDirection->_direction = ECS::DirectionComponent::UP;
			}
			else if (keyCode == ECS::DirectionComponent::DOWN)
			{
				pDirection->_direction = ECS::DirectionComponent::DOWN;
			}
			else if (keyCode == ECS::DirectionComponent::LEFT)
			{
				pDirection->_direction = ECS::DirectionComponent::LEFT;
			}
			else if (keyCode == ECS::DirectionComponent::RIGHT)
			{
				pDirection->_direction = ECS::DirectionComponent::RIGHT;
			}
		}
	}

	
}

void InputSystem::exit()
{

}