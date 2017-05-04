#include "BoardView.h"

BoardView::BoardView(Board *b)
{
	mainBoard = b;
}

BoardView::~BoardView()
{
}

void BoardView::Show() const
{
	int size = mainBoard->getSize();

	printf("\n");
	for (size_t i = 0; i < size; i++) 
	{
		for (size_t j = 0; j < size; j++) 
		{
			Sign cell = mainBoard->getCell(i, j);
			switch (cell) {
			case Sign::White:
				printf("0");
				break;
			case Sign::Black:
				printf("X");
				break;
			default:
				printf("_");
				break;
			}
			printf(" ");
		}
		printf("\n");
	}
}

void BoardView::Swap(Sign& a1, Sign& a2)
{
	Sign buff = a1;
	a1 = a2;
	a2 = buff;
}

void BoardView::StartGame()
{
	int line = 0;
	int column = 0;
	Sign whoWillMove = Sign::White;
	Sign whoMoved = Sign::Black;

	while (mainBoard->isWin() == Turn::Continue)
	{
		Show();
		do
		{
			printf("%d player: input line and column\n", whoWillMove);
			scanf("%d %d", &line, &column);
		}
		while (!mainBoard->makeMove(line, column, whoWillMove));

		Swap(whoWillMove, whoMoved);
	}

	Show();
	printf("Game over\n");
	if (mainBoard->isWin() == Turn::Draw)
	{
		printf("Draw");
		return;
	}
	else
	{
		Swap(whoWillMove, whoMoved);
		printf("%d player win", whoWillMove);
		return;
	}
}
