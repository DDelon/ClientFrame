#ifndef __GAME_INFO_H__
#define __GAME_INFO_H__
#include <assert.h>

#define ROW 48
#define COL 32

#define BLOCK_WIDTH 20
#define BLOCK_HEIGHT 20

#define NULL_BLOCK		(1 << 1)
#define MOVEING_BLOCK	(1 << 2)
#define WAIT_FULL_BLOCK	(1 << 3)
#define FULL_BLOCK		(1 << 4)

class GameInfo
{
public:
	static GameInfo *getInstance();

	void setBlock(int row, int col, int blockType);

	int getBlock(int row, int col);

	void setScore(int score) { _score = score; }

	int getScore() { return _score; }

	void setKeyCode(int code) { _keyCode = code; }

	int getKeyCode() { return _keyCode; }

private:
	GameInfo();
	~GameInfo();

	void initMap();

private:
	static GameInfo *_pInstance;

	int _map[ROW][COL];

	int _score;

	int _keyCode;
};

#endif
