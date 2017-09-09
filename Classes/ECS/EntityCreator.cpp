#include "EntityCreator.h"
#include "Component.h"
#include "EntityManager.h"
using namespace ECS;

EntityCreator::EntityCreator()
{
}

EntityCreator::~EntityCreator()
{
}

int EntityCreator::createBlock(int shapeType)
{
	int entityId = EntityManager::getInstance()->createEntity();

}