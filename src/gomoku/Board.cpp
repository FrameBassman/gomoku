#include "Board.h"

Board::Board()
{
	for (size_t i = 0; i < FIELD_SIZE; ++i)
	{
		for (int j = 0; j < FIELD_SIZE; ++j)
		{
			b[i][j] = -1;
		}
	}

	pointsLeft = FIELD_SIZE * FIELD_SIZE;
	lastModified[0] = -1;
	lastModified[1] = -1;
}

Board::~Board()
{
}

bool Board::makeMove(const int x, const int y, const Sign sign)
{
	if (x > FIELD_SIZE - 1 || y > FIELD_SIZE - 1)
		return false;

	if (getCell(x, y) == Sign::Free)
	{
		if (sign == Sign::White)
			b[x][y] = 0;
		else if (sign == Sign::Black)
			b[x][y] = 1;

		lastModified[0] = x;
		lastModified[1] = y;
		pointsLeft--;
		return true;
	}

	return false;
}

int Board::getSize()
{
	return FIELD_SIZE;
}

Turn Board::isWin()
{
	if (pointsLeft == 0)
		return Turn::Draw;

	if (lastModified[0] == -1 && lastModified[1] == -1)
		return Turn::Continue;

	int counter = 0;
	Sign sign = Sign::White;

	//x
	for (int i = 0; i < FIELD_SIZE; ++i)
	{
		if (sign == getCell(lastModified[0], i))
			counter++;
		else
		{
			counter = 0;
			sign = getCell(lastModified[0], i);
		}

		if (counter >= CON_MAX)
		{
			counter = 0;
			if (sign == Sign::White)
				return Turn::X_win;
			if (sign == Sign::Black)
				return Turn::Y_win;
		}
	}

	//y
	for (int i = 0; i < FIELD_SIZE; ++i)
	{
		if (sign == getCell(i, lastModified[1]))
			counter++;
		else
		{
			counter = 0;
			sign = getCell(i, lastModified[1]);
		}

		if (counter >= CON_MAX)
		{
			if (sign == Sign::White)
				return Turn::X_win;
			if (sign == Sign::Black)
				return Turn::Y_win;
		}
	}

	//TODO:Need to add logic for diagonals

	return Turn::Continue;
}

Sign Board::getCell(const int x, const int y) const
{
	if (b[x][y] == 0)
		return Sign::White;
	if (b[x][y] == 1)
		return Sign::Black;

	return Sign::Free;
}
