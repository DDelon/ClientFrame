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

int EntityManager::createEntity()
{
	int entityId = _entityFlagVec.size();
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

	_componentContainer[componentType][entityId] = pComponent;

}

void EntityManager::removeComponent(int componentType, int entityId)
{
	std::vector<int>::iterator iterFlag = _entityFlagVec.begin() + entityId;
	_entityFlagVec.erase(iterFlag);
	ECS::Component *pComponent = _componentContainer[componentType][entityId];
	if (pComponent != nullptr)
	{
		delete pComponent;
	}

	_componentContainer[componentType][entityId] = nullptr;
}

ECS::Component *EntityManager::getEntity(int componentType, int entityId)
{
	ECS::Component *pComponent = _componentContainer[componentType][entityId];
	return pComponent;
}