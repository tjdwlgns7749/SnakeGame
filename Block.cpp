#include "Block.h"

Block::Block()
{

}

void Block::FoodCreat(int Width, int Height)
{
	m_iCurClock = clock();
	if (m_iFoodCount < m_iFoodMax && m_iCurClock - m_iFoodClock > FOODTIME)
	{
		FoodSetting(Width, Height);
		m_iFoodClock = m_iCurClock;
		FoodDraw();
		m_iFoodCount++;
	}
}

void Block::BlockDelete(list<BlockState>list)
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
		m_DrawManager.ErasePoint(iter->m_BlockPositionX, iter->m_BlockPositionY);
}

void Block::AllDelet()
{
	BlockDelete(FoodBlockList);
	FoodBlockList.clear();
	BlockDelete(ObstacleBlockList);
	ObstacleBlockList.clear();
}

void Block::FoodDelete(int x, int y)
{
	auto iter = FoodBlockList.begin();

	while (1)
	{
		if (iter->m_BlockPositionX == x && iter->m_BlockPositionY == y)
			break;
		else
			iter++;
	}
	FoodBlockList.erase(iter);
	m_iFoodCount--;
}

bool Block::_Check(list<BlockState>list, int x, int y)
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->m_BlockPositionX == x && iter->m_BlockPositionY == y)
			return true;
	}
	return false;
}

bool Block::Check(int x, int y, BLOCK enumBlock)
{
	bool ReturnCheck = false;

	if (enumBlock == BLOCK_WALL)
		ReturnCheck = _Check(MapBlockList, x, y);
	else if (enumBlock == BLOCK_OBSTACLE)
		ReturnCheck = _Check(ObstacleBlockList, x, y);
	else if (enumBlock == BLOCK_POINT)
		ReturnCheck = _Check(FoodBlockList, x, y);

	return ReturnCheck;
}


void Block::FoodDraw()
{
	for (auto iter = FoodBlockList.begin(); iter != FoodBlockList.end(); iter++)
		m_DrawManager.DrawPoint(iter->m_strBlock, iter->m_BlockPositionX, iter->m_BlockPositionY);
}

bool Block::FoodCheck(list<BlockState>list, int x, int y)
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
	{
		if (iter->m_BlockPositionX == x && iter->m_BlockPositionY == y)
			return false;
	}
	return true;
}

void Block::FoodSetting(int Width, int Height)
{
	int x, y = 0;

	while (1)
	{
		x = (rand() % (Width - 2)) + 1;
		y = (rand() % (Height - 2)) + 1;

		if (FoodCheck(ObstacleBlockList, x, y))
			break;
	}
	BlockSetting("¢½", BLOCK_POINT, x, y);
}

void Block::ObstacleSetting(int Width, int Height, int ObstacleCount)
{
	int x, y = 0;

	for (int i = 0; i < ObstacleCount; i++)
	{
		x = (rand() % (Width - 2)) + 1;
		y = (rand() % (Height - 2)) + 1;

		BlockSetting("¢Ã", BLOCK_OBSTACLE, x, y);
	}
}

void Block::BlockSetting(string strBlock, BLOCK enumBlock, int x, int y)
{
	BlockState Block;

	if (enumBlock == BLOCK_WALL)
	{
		Block = { strBlock, enumBlock, x, y, 0, 0 };
		MapBlockList.push_back(Block);
	}
	else if (enumBlock == BLOCK_OBSTACLE)
	{
		Block = { strBlock, enumBlock, x, y, 0, 0 };
		ObstacleBlockList.push_back(Block);
	}
	else if (enumBlock == BLOCK_POINT)
	{
		Block = { strBlock, enumBlock, x, y, 0, 0 };
		FoodBlockList.push_back(Block);
	}
}

void Block::BlockDraw(list<BlockState>list)
{
	for (auto iter = list.begin(); iter != list.end(); iter++)
		m_DrawManager.DrawPoint(iter->m_strBlock, iter->m_BlockPositionX, iter->m_BlockPositionY);
}

Block::~Block()
{


}