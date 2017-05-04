#pragma once
#include "Board.h"
#include <stdio.h>
class BoardView
{
public:
	BoardView(Board *b);
	~BoardView();
	void StartGame();
private:
	Board *mainBoard;
	void Show() const;
	void Swap(Sign& a1, Sign& a2);
};

