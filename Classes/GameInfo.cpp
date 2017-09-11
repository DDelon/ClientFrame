#include "GameInfo.h"
#include "ECS/Component.h"

GameInfo::GameInfo()
{
	_score = 0;
	_keyCode = ECS::DirectionComponent::NONE;
	this->initMap();
}
GameInfo::~GameInfo()
{

}


GameInfo *GameInfo::_pInstance = nullptr;
GameInfo *GameInfo::getInstance()
{
	if (_pInstance == nullptr)
	{
		_pInstance = new GameInfo();
	}

	return _pInstance;
}

void GameInfo::initMap()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			_map[i][j] = NULL_BLOCK;
		}
	}
}

void GameInfo::setBlock(int row, int col, int blockType)
{
	assert(row < ROW);
	assert(row >= 0);
	assert(col >= 0);
	assert(col < COL);

	_map[row][col] = blockType;
}

int GameInfo::getBlock(int row, int col)
{
	assert(row < ROW);
	assert(row >= 0);
	assert(col >= 0);
	assert(col < COL);

	return _map[row][col];
}
