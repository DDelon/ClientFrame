#ifndef __ENTITY_CREATOR_H__
#define __ENTITY_CREATOR_H__

class EntityCreator
{
public:
	EntityCreator();
	~EntityCreator();

public:
	//������
	static unsigned int createRectShape();
	//������
	static unsigned int createSquare();
	//L��
	static unsigned int createLShape();

	//����������
	static unsigned int createBlock(int row, int col);
};
#endif
