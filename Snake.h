#pragma once
#include "Block.h"

enum DIRECTION
{
	DIRECTION_DEFAULT,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN
};

#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

#define MOVESPEED 250

class Snake
{
private:
	DIRECTION m_eSnakeDirection;
	MapDraw m_DrawManager;
	Block m_BlockManager;
	list<BlockState>SnakeList;

	int m_iCurClock;
	int m_iMoveClock;
	int m_iMoveSpeed;
	bool m_bSnakeDraw;
	int m_Tailcount;

public:

	void SelectDirection();
	void Move();
	void SnakeDraw();
	void SnakeSetting(string strBlock, BLOCK enumBlock, int x, int y);
	void CreateTail();
	void tailMove();
	void SnakeDelete();
	void SnakeClear();
	bool HeadTailCheck();
	void test();

	inline void SpeedUp()
	{
		if (m_iMoveSpeed > 50)
			m_iMoveSpeed -= 10;
	}
	inline int GetHeadX()
	{
		auto iter = SnakeList.begin();
		return iter->m_BlockPositionX;
	}
	inline int GetHeadY()
	{
		auto iter = SnakeList.begin();
		return iter->m_BlockPositionY;
	}
	inline void MoveSpeedReset() { m_iMoveSpeed = MOVESPEED; }
	inline void DirectionReset() { m_eSnakeDirection = DIRECTION_DEFAULT; }

	Snake();
	~Snake();

};

