#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "Component.h"

class EntityManager
{
public:
	typedef std::vector<ECS::Component *> componentVec;
public:
	static EntityManager *getInstance();

	EntityCreator *getEntityCreator() { return _pCreator; }

	int getEntitySize() { return _entityFlagVec.size(); }

	int getEntityFlag(int entityId) { return _entityFlagVec[entityId]; }

	int createEntity();

	void removeEntity(int entityId);

	void addComponent(ECS::Component *pComponent, int componentType, int entityId);

	void removeComponent(int componentType, int entityId);

	ECS::Component *getEntity(int componentType, int entityId);

private:
	EntityManager();
	~EntityManager();

private:
	static EntityManager *_pInstance;

	std::vector<int> _entityFlagVec;
	std::vector<componentVec> _componentContainer;
};

#endif
