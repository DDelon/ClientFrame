#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

#include "System.h"

class InputSystem : public System
{
public:
	InputSystem(int priority);
	~InputSystem();

public:
	void enter();

	void excute(float dt);

	void exit();
};

#endif
