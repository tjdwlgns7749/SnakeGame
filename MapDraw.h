#pragma once
#include "Mecro.h"
class MapDraw
{
public:
	void ErasePoint(int x, int y);
	void DrawPoint(string str, int x, int y);
	void DrawMidText(string str, int x, int y);
	MapDraw();
	~MapDraw();

	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

