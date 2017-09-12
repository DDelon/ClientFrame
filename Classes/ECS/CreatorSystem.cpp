#include "CreatorSystem.h"
#include "EntityManager.h"
#include "EntityCreator.h"

CreatorSystem::CreatorSystem(int priority)
{
	this->_priority = priority;
}

CreatorSystem::~CreatorSystem()
{

}

void CreatorSystem::enter()
{

}

void CreatorSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();
	if (size == 0)
	{
		EntityCreator::createRectShape();
	}
}

void CreatorSystem::exit()
{

}