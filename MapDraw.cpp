#include "MapDraw.h"

MapDraw::MapDraw()
{
}

void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}


/*void GameManager::DrawMap()
{
	for (int i = 0; i < m_iMapHeight; i++)
	{
		for (int j = 0; j < m_iMapWidth; j++)
		{
			if (i == 0 || i == m_iMapHeight - 1)
			{
				cout << "¢Ë";
			}
			else if (j == 0 || j == m_iMapWidth - 1)
			{
				if (i != 0 || i != m_iMapHeight)
					cout << "¢Ë";
			}
			else
				cout << "  ";
		}
	}
}*/

MapDraw::~MapDraw()
{
}
