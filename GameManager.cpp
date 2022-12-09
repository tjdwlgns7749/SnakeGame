#include "GameManager.h"

GameManager::GameManager()
{
	m_iMapWidth = WIDTH;
	m_iMapHeight = HEIGHT;
}

void GameManager::DrawScore()
{
	string str = "Score : ";
	str += to_string(m_iScore);
	m_DrawManager.DrawMidText(str, m_iMapWidth, m_iMapHeight + 2);
}

void GameManager::GamePlay()
{
	system("cls");
	m_Snake.SnakeSetting("⊙", BLOCK_HEAD, m_iMapWidth / 2, m_iMapHeight / 2);//뱀
	m_Block.ObstacleSetting(m_iMapWidth, m_iMapHeight, m_iObstacleCount);//장애물
	DrawMap();
	DrawScore();
	DrawObstacle();

	while (1)
	{
		m_Block.FoodCreat(m_iMapWidth, m_iMapHeight);

		m_Snake.SelectDirection();
		m_Snake.Move();

		if (m_Block.Check(m_Snake.GetHeadX(), m_Snake.GetHeadY(), BLOCK_WALL))
			break;
		if (m_Block.Check(m_Snake.GetHeadX(), m_Snake.GetHeadY(), BLOCK_OBSTACLE))
			break;
		if (m_Snake.HeadTailCheck())
			break;
		if (m_Block.Check(m_Snake.GetHeadX(), m_Snake.GetHeadY(), BLOCK_POINT))
		{
			m_Block.FoodDelete(m_Snake.GetHeadX(), m_Snake.GetHeadY());
			m_iScore++;
			m_Snake.CreateTail();
			DrawScore();
			m_Snake.SpeedUp();
		}
		m_Snake.SnakeDraw();
	}
	m_Block.AllDelet();
	m_Snake.SnakeClear();
	m_iScore = 0;
	m_Snake.MoveSpeedReset();
	m_Snake.DirectionReset();
}

void GameManager::DrawDisPlay()
{
	m_Block.MapDraw();
	DrawMenu();
}

void GameManager::GameSetting(int width, int height)
{
	BlockState MapBlock;


	m_iObstacleCount = 20;
	m_iScore = 0;
	m_Block.FoodSetting();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				m_Block.BlockSetting("▦", BLOCK_WALL, x, y);
			}
		}
	}
}

void GameManager::DrawMenu()
{
	m_DrawManager.gotoxy(m_iMapWidth * 0.8 - 4, m_iMapHeight * 0.2);
	cout << "★ ☆ ★ Snake Game ★ ☆ ★";
	m_DrawManager.gotoxy(m_iMapWidth * 0.9, m_iMapHeight * 0.3);
	cout << "1.게임 시작";
	m_DrawManager.gotoxy(m_iMapWidth * 0.9, m_iMapHeight * 0.4);
	cout << "2.게임 종료";
	m_DrawManager.gotoxy(m_iMapWidth * 0.9, m_iMapHeight * 0.5);
	cout << "선택 : ";
	m_DrawManager.gotoxy(m_iMapWidth + 3, m_iMapHeight * 0.5);
}

void GameManager::Game()
{
	char buf[256];
	int Select = 0;

	sprintf(buf, "mode con: lines=%d cols=%d", m_iMapHeight + 3, (m_iMapWidth * 2) + 1);
	system(buf);

	while (1)
	{
		system("cls");
		GameSetting(m_iMapWidth, m_iMapHeight);
		DrawScore();
		DrawDisPlay();
		cin >> Select;

		switch (Select)
		{
		case GAMEMENU_START:
			GamePlay();
			break;
		case GAMEMENU_EXIT:
			return;
		}
	}
}


GameManager::~GameManager()
{



}