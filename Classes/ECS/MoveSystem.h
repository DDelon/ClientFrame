#ifndef __MOVE_SYSTEM_H__
#define __MOVE_SYSTEM_H__
#include "System.h"

class MoveSystem : public System
{
public:
	MoveSystem(int priority);
	~MoveSystem();

public:
	void enter();

	void excute(float dt);

	void exit();

};

#endif
