#include "SystemManager.h"
#include "System.h"
SystemManager::SystemManager()
{
	_frame = 0;
}

SystemManager::~SystemManager()
{

}

SystemManager *SystemManager::_pInstance = nullptr;
SystemManager *SystemManager::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new SystemManager();
	}

	return _pInstance;
}

void SystemManager::addSystem(System *pSystem)
{
	_systemVec.push_back(pSystem);

	std::sort(_systemVec.begin(), _systemVec.end(), [=](System *pSystem1, System *pSystem2) {

		return (pSystem1->getPriority() < pSystem2->getPriority());

	});
}

void SystemManager::update(float dt)
{
	++_frame;
	for (auto iter : _systemVec)
	{
		iter->excute(dt);
	}
}