#ifndef __TIME_SYSTEM_H__
#define __TIME_SYSTEM_H__

#include "System.h"

class TimeSystem : public System
{
public:
	TimeSystem(int priority);
	~TimeSystem();

public:
	void enter();

	void excute(float dt);

	void exit();
};

#endif
