#include "TimeSystem.h"
#include "EntityManager.h"
#include "Component.h"

TimeSystem::TimeSystem(int priority)
{
	this->_priority = priority;
}

TimeSystem::~TimeSystem()
{
}

void TimeSystem::enter()
{

}

void TimeSystem::excute(float dt)
{
	int size = EntityManager::getInstance()->getEntitySize();

	for (int i = 0; i < size; ++i)
	{
		int flag = EntityManager::getInstance()->getEntityFlag(i);
		if ((flag & (TIME_COMPONENT | RENDER_COMPONENT)) == (TIME_COMPONENT | RENDER_COMPONENT))
		{
			ECS::RenderComponent *pRender = static_cast<ECS::RenderComponent *>(EntityManager::getInstance()->getEntityComponent(RENDER_COMPONENT, i));
			ECS::TimeComponent *pTime = static_cast<ECS::TimeComponent *>(EntityManager::getInstance()->getEntityComponent(TIME_COMPONENT, i));
			if (pTime->_isArrival)
			{
				pRender->_pBlockLayer->runAction(Sequence::create(DelayTime::create(pTime->_timeConst), CallFuncN::create([=](Ref *pSender){
					pTime->_isArrival = true;
				}), nullptr));
			}
		}
	}
}

void TimeSystem::exit()
{
}