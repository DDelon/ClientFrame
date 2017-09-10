#include "EntityManager.h"
EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
}

EntityManager *EntityManager::_pInstance = nullptr;
EntityManager *EntityManager::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new EntityManager();
	}

	return _pInstance;
}

unsigned int EntityManager::getBitOne(unsigned int val, unsigned int number, int index)
{
	if (val == 1)
	{
		return index;
	}
	else if (number == 1)
	{
		return -1;
	}
	else
	{
		unsigned int result = -1;
		unsigned int temp = val;
		unsigned int half_num = number / 2;
		int offset = 32 - half_num - index;
		temp = temp << offset;
		temp = temp >> offset;

		result = getBitOne(temp, half_num, index);
		if (result != -1)
			return result;

		result = getBitOne(val >> half_num, half_num, index + half_num);
		if (result != -1)
			return result;

	}
}

void EntityManager::registerComponents(int num)
{
	for (int i = 0; i < num; i++)
	{
		componentVec vec;
		_componentContainer.push_back(vec);
	}
}

unsigned int EntityManager::createEntity()
{
	unsigned int entityId = _entityFlagVec.size();
	_entityFlagVec.push_back(0);

	for (int i = 0; i < _componentContainer.size(); ++i)
	{
		_componentContainer[i].push_back(nullptr);
	}

	return entityId;
}

void EntityManager::removeEntity(int entityId)
{
	for (int i = 0; i < _componentContainer.size(); ++i)
	{
		std::vector<ECS::Component *>::iterator iter = _componentContainer[i].begin() + entityId;
		ECS::Component *pComponent = *iter;
		if (pComponent != NULL)
		{
			delete pComponent;
		}

		_componentContainer[i].erase(iter);
	}

	_entityFlagVec.erase(_entityFlagVec.begin() + entityId);
}

void EntityManager::addComponent(ECS::Component *pComponent, int componentType, int entityId)
{
	_entityFlagVec[entityId] |= componentType;

	unsigned int index = getBitOne(componentType, 32, 0)-1;
	_componentContainer[index][entityId] = pComponent;

}

void EntityManager::removeComponent(int componentType, int entityId)
{
	std::vector<int>::iterator iterFlag = _entityFlagVec.begin() + entityId;
	_entityFlagVec.erase(iterFlag);
	unsigned int index = getBitOne(componentType, 32, 0) - 1;
	ECS::Component *pComponent = _componentContainer[index][entityId];
	if (pComponent != nullptr)
	{
		delete pComponent;
	}

	_componentContainer[index][entityId] = nullptr;
}

ECS::Component *EntityManager::getEntityComponent(int componentType, int entityId)
{
	unsigned int index = getBitOne(componentType, 32, 0) - 1;
	ECS::Component *pComponent = _componentContainer[index][entityId];
	return pComponent;
}