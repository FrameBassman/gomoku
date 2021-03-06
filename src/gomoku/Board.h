#pragma once
enum Turn 
{
	Draw,
	X_win,
	Y_win,
	Continue
};
enum Sign 
{
	White,
	Black,
	Free
};

class Board
{
public:
	Board();
	~Board();
	bool makeMove(int x, int y, Sign sign);
	int getSize();
	Turn isWin();
	Sign getCell(int x, int y) const;
private:
	static const int FIELD_SIZE = 3;
	static const int CON_MAX = 3;
	size_t pointsLeft;
	int b[FIELD_SIZE][FIELD_SIZE];
	int lastModified[2];
};