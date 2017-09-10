#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__
#include "System.h"
#include "cocos2d.h"
USING_NS_CC;

class RenderSystem : public System
{
public:
	RenderSystem(int priority, Node *pLayer);
	~RenderSystem();

public:
	virtual void enter();

	virtual void excute(float dt);

	virtual void exit();

private:
	Node *_pLayer;
};

#endif
