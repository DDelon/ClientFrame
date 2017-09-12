#ifndef __ENTITY_CREATOR_H__
#define __ENTITY_CREATOR_H__

class EntityCreator
{
public:
	EntityCreator();
	~EntityCreator();

public:
	//长方形
	static unsigned int createRectShape();
	//正方形
	static unsigned int createSquare();
	//L形
	static unsigned int createLShape();

	//创建单个块
	static unsigned int createBlock(int row, int col);
};
#endif
