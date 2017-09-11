#ifndef __WRITE_TO_MAP_SYSTEM_H__
#define __WRITE_TO_MAP_SYSTEM_H__
#include "System.h"

class WriteToMapSystem : public System
{
public:
	WriteToMapSystem(int priority);
	~WriteToMapSystem();

public:
	virtual void enter();

	virtual void excute(float dt);

	virtual void exit();

};

#endif