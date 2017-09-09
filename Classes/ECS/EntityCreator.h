#ifndef __ENTITY_CREATOR_H__
#define __ENTITY_CREATOR_H__

class EntityCreator
{
public:
	EntityCreator();
	~EntityCreator();

public:
	static int createBlock(int shapeType);
};
#endif
