#include "RenderSystem.h"
#include "EntityManager.h"
#include "Component.h"
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
		if (flag & (RENDER_COMPONENT | POSITION_COMPONENT) == (RENDER_COMPONENT | POSITION_COMPONENT))
		{
			RenderComponent *pRender = static_cast<RenderComponent *>(EntityManager::getInstance()->getEntity(RENDER_COMPONENT, i));
			PositionComponent *pPosition = static_cast<PositionComponent *>(EntityManager::getInstance()->getEntity(POSITION_COMPONENT, i));

			if (pRender->_pRender->getParent() == nullptr)
			{
				_pLayer->addChild(pRender->_pRender);
			}

			pRender->_pRender->setPosition(Vec2(pPosition->_x, pPosition->_y));
		}
	}
}

void RenderSystem::exit()
{

}