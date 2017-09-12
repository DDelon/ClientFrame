#include "RenderSystem.h"
#include "EntityManager.h"
#include "Component.h"
#include "GameInfo.h"
using namespace ECS;

RenderSystem::RenderSystem(int priority, Node *pLayer)
{
	this->_priority = priority;
	this->_pLayer = pLayer;
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::enter()
{

}

void RenderSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();

	for (int i = 0; i < size; ++i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);
		if ((flag & (RENDER_COMPONENT | POSITION_COMPONENT)) == (RENDER_COMPONENT | POSITION_COMPONENT))
		{
			RenderComponent *pRender = static_cast<RenderComponent *>(EntityManager::getInstance()->getEntityComponent(RENDER_COMPONENT, i));
			PositionComponent *pPosition = static_cast<PositionComponent *>(EntityManager::getInstance()->getEntityComponent(POSITION_COMPONENT, i));

			if (pRender->_pBlockLayer->getParent() == nullptr)
			{
				_pLayer->addChild(pRender->_pBlockLayer);
				pRender->_pBlockLayer->release();
			}

			pRender->_pBlockLayer->setPosition(Vec2(pPosition->_x, pPosition->_y));
		}
	}

	//render all fixed block

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (GameInfo::getInstance()->getBlock(i, j) == WAIT_FULL_BLOCK)
			{
				GameInfo::getInstance()->setBlock(i, j, FULL_BLOCK);
				Sprite *pFixedBlock = Sprite::create("block4.png");
				pFixedBlock->setPosition(Vec2((j + 1)*BLOCK_WIDTH - BLOCK_WIDTH / 2, (i + 1)*BLOCK_HEIGHT - BLOCK_HEIGHT / 2));
				_pLayer->addChild(pFixedBlock);
			}
		}
	}
}

void RenderSystem::exit()
{

}