#include "BoardView.h"

BoardView::BoardView(Board *b)
{
	myB = b;
}

BoardView::~BoardView()
{
}

void BoardView::Show() {
	int size = myB->getSize();

	printf("\n");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			
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

void BoardView::StartGame() {
	while (myB->isWin() == Continue) {
		int line = 0;
		int column = 0;

		Show();
		printf("First player: input line and column\n");
		scanf("%d %d", &line, &column);
		myB->makeMove(line, column, Sign::White);
		
		line = 0;
		column = 0;

		Show();
		printf("Second player: input line and column\n");
		scanf("%d %d", &line, &column);
		myB->makeMove(line, column, Sign::Black);
	}

	printf("Game over");
}
