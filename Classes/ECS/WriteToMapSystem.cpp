#include "WriteToMapSystem.h"
#include "EntityManager.h"
#include "Component.h"
#include "CheckToBaseSystem.h"
#include "GameInfo.h"

WriteToMapSystem::WriteToMapSystem(int priority)
{
	this->_priority = priority;
}

WriteToMapSystem::~WriteToMapSystem()
{

}

void WriteToMapSystem::enter()
{
	
}

void WriteToMapSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize()-1;

	for (int i = size; i >= 0; --i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);
		if ((flag & (STATUS_COMPONENT | ENTITY_TYPE_COMPONENT | RENDER_COMPONENT)) == (STATUS_COMPONENT | ENTITY_TYPE_COMPONENT | RENDER_COMPONENT))
		{
			ECS::StatusComponent *pStatus = static_cast<ECS::StatusComponent *>(EntityManager::getInstance()->getEntityComponent(STATUS_COMPONENT, i));
			ECS::EntityTypeComponent *pType = static_cast<ECS::EntityTypeComponent *>(EntityManager::getInstance()->getEntityComponent(ENTITY_TYPE_COMPONENT, i));
			ECS::RenderComponent *pRender = static_cast<ECS::RenderComponent *>(EntityManager::getInstance()->getEntityComponent(RENDER_COMPONENT, i));

			if (pStatus->_status == ECS::StatusComponent::STOP)
			{
				//full data to game info map
				Vector<Node *> childrenVec = pRender->_pBlockLayer->getChildren();
				{
					for (auto iter : childrenVec)
					{
						Vec2 worldPos = iter->convertToWorldSpace(iter->getAnchorPointInPoints());
						Vec2 rowCol = CheckToBaseSystem::convertToRowCol(worldPos);
						GameInfo::getInstance()->setBlock(rowCol.x, rowCol.y, WAIT_FULL_BLOCK);
					}
				}

				//delete entity
				EntityManager::getInstance()->removeEntity(i);
				continue;
			}
			else
			{
				//full data to game info map
				Vector<Node *> childrenVec = pRender->_pBlockLayer->getChildren();
				{
					for (auto iter : childrenVec)
					{
						Vec2 worldPos = iter->convertToWorldSpace(iter->getAnchorPointInPoints());
						Vec2 rowCol = CheckToBaseSystem::convertToRowCol(worldPos);
						GameInfo::getInstance()->setBlock(rowCol.x, rowCol.y, MOVEING_BLOCK);
					}
				}
			}
		}
	}
}

void WriteToMapSystem::exit()
{

}