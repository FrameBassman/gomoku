#include "BoardView.h"

BoardView::BoardView(Board *b)
{
	myB = b;
}

BoardView::~BoardView()
{
}

void BoardView::Show() const
{
	int size = myB->getSize();

	printf("\n");
	for (size_t i = 0; i < size; i++) 
	{
		for (size_t j = 0; j < size; j++) 
		{
			Sign cell = myB->getCell(i, j);
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

void BoardView::StartGame() 
{
	int line = 0;
	int column = 0;
	Sign whoShouldMove = Sign::White;

	while (myB->isWin() == Continue) 
	{
		Show();
		do
		{
			printf("%d player: input line and column\n", whoShouldMove);
			scanf("%d %d", &line, &column);
		}
		while (!myB->makeMove(line, column, whoShouldMove));

		if (whoShouldMove == Sign::White)
			whoShouldMove = Sign::Black;
		else
			whoShouldMove = Sign::White;
	}

	printf("Game over");
}
