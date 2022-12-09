#include "Snake.h"

Snake::Snake()
{
	m_eSnakeDirection = DIRECTION_DEFAULT;
	m_iCurClock = 0;
	m_iMoveClock = 0;
	m_iMoveSpeed = 250;
	m_bSnakeDraw = false;
}

bool Snake::HeadTailCheck()
{
	int x = GetHeadX();
	int y = GetHeadY();
	bool ReturnCheck = false;

	for (auto iter = SnakeList.begin(); iter != SnakeList.end(); iter++)
	{
		if (iter->m_eBlockKinds != BLOCK_HEAD)
		{
			if (iter->m_SnakeLastPositionX == x && iter->m_SnakeLastPositionY == y)
				return  true;
			else
				ReturnCheck = false;
		}
	}
	return ReturnCheck;
}

void Snake::SnakeClear()
{
	SnakeList.clear();
}

void Snake::SnakeDelete()
{
	for (auto iter = SnakeList.begin(); iter != SnakeList.end(); iter++)
		m_DrawManager.ErasePoint(iter->m_BlockPositionX, iter->m_BlockPositionY);

}

void Snake::tailMove()
{
	int SaveX, SaveY, ReturnX, ReturnY = 0;
	
	for (auto iter = SnakeList.begin(); iter != SnakeList.end(); iter++)
	{
		if (iter->m_eBlockKinds == BLOCK_HEAD)
		{
			ReturnX = iter->m_SnakeLastPositionX;
			ReturnY = iter->m_SnakeLastPositionY;
		}
		else if (iter->m_eBlockKinds == BLOCK_TAIL)
		{
			
			iter->m_SnakeLastPositionX = iter->m_BlockPositionX;
			iter->m_SnakeLastPositionY = iter->m_BlockPositionY;
			SaveX = iter->m_BlockPositionX;
			SaveY = iter->m_BlockPositionY;
			iter->m_BlockPositionX = ReturnX;
			iter->m_BlockPositionY = ReturnY;
			ReturnX = SaveX;
			ReturnY = SaveY;
		}
	}
}

void Snake::CreateTail()
{
	BlockState tail;

	auto iter = SnakeList.rbegin();

	tail = { "¡Û",BLOCK_TAIL,iter->m_SnakeLastPositionX,iter->m_SnakeLastPositionY,0,0 };
	SnakeList.push_back(tail);
}


void Snake::SnakeDraw()
{
	if (m_bSnakeDraw)
	{
		for (auto iter = SnakeList.begin(); iter != SnakeList.end(); iter++)
			m_DrawManager.DrawPoint(iter->m_strBlock, iter->m_BlockPositionX, iter->m_BlockPositionY);
	}
	m_bSnakeDraw = false;
}

void Snake::SnakeSetting(string strBlock, BLOCK enumBlock, int x, int y)
{
	if (enumBlock == BLOCK_HEAD)
	{
		BlockState SnakeHead;
		SnakeHead = { strBlock,enumBlock,x,y,0,0 };
		SnakeList.push_back(SnakeHead);
	}
}

void Snake::SelectDirection()
{
	char ch;

	if (kbhit())
	{
		ch = getch();

		switch (ch)
		{
		case LEFT:
			if (m_eSnakeDirection != DIRECTION_RIGHT)
				m_eSnakeDirection = DIRECTION_LEFT;
			break;
		case RIGHT:
			if (m_eSnakeDirection != DIRECTION_LEFT)
				m_eSnakeDirection = DIRECTION_RIGHT;
			break;
		case UP:
			if (m_eSnakeDirection != DIRECTION_DOWN)
				m_eSnakeDirection = DIRECTION_UP;
			break;
		case DOWN:
			if (m_eSnakeDirection != DIRECTION_UP)
				m_eSnakeDirection = DIRECTION_DOWN;
			break;
		}
	}
}

void Snake::Move()
{
	auto iter = SnakeList.begin();

	m_iCurClock = clock();

	if (m_iCurClock - m_iMoveClock >= m_iMoveSpeed)
	{

		SnakeDelete();
		iter->m_SnakeLastPositionX = iter->m_BlockPositionX;
		iter->m_SnakeLastPositionY = iter->m_BlockPositionY;
		switch (m_eSnakeDirection)
		{
		case DIRECTION_DEFAULT:
			break;
		case DIRECTION_LEFT:
			iter->m_BlockPositionX--;
			break;
		case DIRECTION_RIGHT:
			iter->m_BlockPositionX++;
			break;
		case DIRECTION_UP:
			iter->m_BlockPositionY--;
			break;
		case DIRECTION_DOWN:
			iter->m_BlockPositionY++;
			break;
		}
		m_iMoveClock = m_iCurClock;
		m_bSnakeDraw = true;
		tailMove();
	}
}

Snake::~Snake()
{

}