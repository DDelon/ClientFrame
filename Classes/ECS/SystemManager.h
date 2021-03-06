#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__
#include "cocos2d.h"
USING_NS_CC;
class System;

class SystemManager
{
public:
	static SystemManager *getInstance();

	void addSystem(System *pSystem);

	void update(float dt);

	int getFrame() { return _frame; }

	void setPause(bool isPause) { _isPause = isPause; }

	bool isPause() { return _isPause; }

private:
	SystemManager();
	~SystemManager();

private:
	static SystemManager *_pInstance;

	std::vector<System *> _systemVec;

	int _frame;

	bool _isPause;
};

#endif
