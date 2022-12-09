#pragma once
#include "Mecro.h"
#include "MapDraw.h"
#include "Block.h"
#include "Snake.h"

#define WIDTH 50
#define HEIGHT 30

class GameManager
{
private:
	MapDraw m_DrawManager;
	Snake m_Snake;
	Block m_Block;
	int m_iMapWidth;
	int m_iMapHeight;
	int m_iObstacleCount = 0;
	int m_iCurClock = 0;
	int m_iScore = 0;


public:
	void Game();
	void DrawMenu();
	void GameSetting(int Width, int Height);
	void DrawDisPlay();
	void GamePlay();
	void DrawScore();



	inline void DrawMap() { m_Block.MapDraw(); };
	inline void DrawObstacle() { m_Block.ObstacleDraw(); };
	GameManager();
	~GameManager();

};

