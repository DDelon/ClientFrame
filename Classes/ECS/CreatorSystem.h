#ifndef __CREATOR_SYSTEM_H__
#define __CREATOR_SYSTEM_H__
#include "System.h"

class CreatorSystem : public System
{
public:
	CreatorSystem(int priority);
	~CreatorSystem();

public:
	virtual void enter();

	virtual void excute(float dt);

	virtual void exit();

};

#endif