#ifndef __CLEAR_MAP_SYSTEM_H__
#define __CLEAR_MAP_SYSTEM_H__

#include "System.h"
#include "cocos2d.h"
USING_NS_CC;

class ClearMapSystem : public System
{
public:
	ClearMapSystem(int priority);
	~ClearMapSystem();

public:
	void enter();

	void excute(float dt);

	void exit();

};

#endif