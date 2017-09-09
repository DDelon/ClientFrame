#include "SystemManager.h"
#include "System.h"
SystemManager::SystemManager()
{

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
}

void SystemManager::update(float dt)
{
	for (auto iter : _systemVec)
	{
		iter->excute(dt);
	}
}