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
	Board *myB;
	void Show() const;
};

