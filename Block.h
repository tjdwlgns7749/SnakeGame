#pragma once
#include "MapDraw.h"

enum BLOCK
{
	BLOCK_HEAD,
	BLOCK_TAIL,
	BLOCK_WALL,
	BLOCK_POINT,
	BLOCK_OBSTACLE
};

enum CHECK
{
	CHECK_DIE = 1,
	CHECK_FOOD,
	CHECK_LIVE
};

#define FOODTIME 1000

struct BlockState
{
	string m_strBlock;
	BLOCK  m_eBlockKinds;
	int m_BlockPositionX;
	int m_BlockPositionY;
	int m_SnakeLastPositionX;
	int m_SnakeLastPositionY;
};

class Block
{
private:
	BlockState m_BlockState;
	MapDraw m_DrawManager;
	list<BlockState>MapBlockList;
	list<BlockState>ObstacleBlockList;
	list<BlockState>FoodBlockList;
	int m_iFoodClock;
	int m_iCurClock;
	int m_iFoodCount;
	int m_iFoodMax;

public:

	void BlockSetting(string strBlock, BLOCK enumBlock, int x, int y);
	void BlockDraw(list<BlockState>list);
	void ObstacleSetting(int Width, int Height, int ObstacleCount);
	void FoodSetting(int Width, int Height);
	void FoodDraw();
	void FoodDelete(int x, int y);
	void AllDelet();
	void BlockDelete(list<BlockState>list);
	void FoodCreat(int Width, int Height);

	bool FoodCheck(list<BlockState>list, int x, int y);
	bool Check(int x, int y, BLOCK enumBlock);
	bool _Check(list<BlockState>list, int x, int y);



	inline void MapDraw() { BlockDraw(MapBlockList); };
	inline void ObstacleDraw() { BlockDraw(ObstacleBlockList); };
	inline void FoodSetting()
	{
		m_iFoodCount = 0;
		m_iFoodMax = 10;
	}
	Block();
	~Block();
};