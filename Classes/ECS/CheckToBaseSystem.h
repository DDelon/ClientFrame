#ifndef __CHECK_TO_BASE_SYSTEM_H__
#define __CHECK_TO_BASE_SYSTEM_H__

#include "System.h"
#include "cocos2d.h"
USING_NS_CC;

class CheckToBaseSystem : public System
{
public:
	CheckToBaseSystem(int priority);
	~CheckToBaseSystem();

public:
	void enter();

	void excute(float dt);

	void exit();

	static Vec2 convertToRowCol(Vec2 worldPos);
};

#endif
