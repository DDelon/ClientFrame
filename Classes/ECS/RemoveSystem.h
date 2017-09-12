#ifndef __REMOVE_SYSTEM_H__
#define __REMOVE_SYSTEM_H__

#include "System.h"

class RemoveSystem : public System
{
public:
	RemoveSystem();
	~RemoveSystem();

public:
	void enter();

	void excute(float dt);

	void exit();
};

#endif