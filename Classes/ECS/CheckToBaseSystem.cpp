#include "CheckToBaseSystem.h"
#include "EntityManager.h"
#include "GameInfo.h"

CheckToBaseSystem::CheckToBaseSystem(int priority)
{
	this->_priority = priority;
}

CheckToBaseSystem::~CheckToBaseSystem()
{

}

void CheckToBaseSystem::enter()
{

}

void CheckToBaseSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();

	for (int i = 0; i < size; ++i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);

		if ((flag & (DIRECTION_COMPONENT | RENDER_COMPONENT | SPEED_COMPONENT | POSITION_COMPONENT | STATUS_COMPONENT)) == (DIRECTION_COMPONENT | RENDER_COMPONENT | SPEED_COMPONENT | POSITION_COMPONENT | STATUS_COMPONENT))
		{
			bool isMoveOver = false;
			ECS::StatusComponent *pStatus = static_cast<ECS::StatusComponent *>(EntityManager::getInstance()->getEntityComponent(STATUS_COMPONENT, i));
			ECS::SpeedComponent *pSpeed = static_cast<ECS::SpeedComponent *>(EntityManager::getInstance()->getEntityComponent(SPEED_COMPONENT, i));
			ECS::RenderComponent *pRender = static_cast<ECS::RenderComponent *>(EntityManager::getInstance()->getEntityComponent(RENDER_COMPONENT, i));
			ECS::DirectionComponent *pDirection = static_cast<ECS::DirectionComponent *>(EntityManager::getInstance()->getEntityComponent(DIRECTION_COMPONENT, i));
			ECS::PositionComponent *pPosition = static_cast<ECS::PositionComponent *>(EntityManager::getInstance()->getEntityComponent(POSITION_COMPONENT, i));
			
			Vec2 oldPosition = pRender->_pBlockLayer->getPosition();
			Vec2 newPosition = Vec2(pPosition->_x, pPosition->_y);


			if (pPosition->_y < 0)
			{
				pPosition->_x = oldPosition.x;
				pPosition->_y = oldPosition.y;

				if (pDirection->_direction == ECS::DirectionComponent::DOWN)
				{
					pStatus->_status = ECS::StatusComponent::STOP;
					log("block move to end");
				}
				pDirection->_direction = ECS::DirectionComponent::NONE;
			}
			else
			{
				
				Vec2 offset = newPosition - oldPosition;

				Vector<Node *> childrenVec = pRender->_pBlockLayer->getChildren();
				for (auto iter : childrenVec)
				{
					Vec2 worldPos = iter->convertToWorldSpace(iter->getAnchorPointInPoints());
					worldPos += offset;
					Vec2 rowCol = CheckToBaseSystem::convertToRowCol(worldPos);
					//log("world position x:%f position y:%f convert row:%f col:%f", worldPos.x, worldPos.y, rowCol.x, rowCol.y);
					int block = GameInfo::getInstance()->getBlock(rowCol.x, rowCol.y);
					if (block == FULL_BLOCK)
					{
						isMoveOver = true;
					}
				}

				if (!isMoveOver)
				{
					pDirection->_direction = ECS::DirectionComponent::NONE;
					continue;
				}

				pPosition->_x = oldPosition.x;
				pPosition->_y = oldPosition.y;
				//
				if (pDirection->_direction == ECS::DirectionComponent::DOWN)
				{
					pStatus->_status = ECS::StatusComponent::STOP;
					log("block move to end");
				}

				pDirection->_direction = ECS::DirectionComponent::NONE;
			}

		}

		
	}
}

void CheckToBaseSystem::exit()
{

}

Vec2 CheckToBaseSystem::convertToRowCol(Vec2 worldPos)
{
	int col = worldPos.x / BLOCK_WIDTH;
	int row = worldPos.y / BLOCK_HEIGHT;
	return Vec2(row, col);
}