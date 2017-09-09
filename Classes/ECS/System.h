#ifndef __SYSTEM_H__
#define __SYSTEM_H__

class System
{
public:
	System();
	virtual ~System();

public:
	virtual void enter() = 0;

	virtual void excute(float dt) = 0;

	virtual void exit() = 0;

	virtual int getPriority() { return _priority; }

protected:
	int _priority;
};

#endif
