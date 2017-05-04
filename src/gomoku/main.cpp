#include "Board.h"
#include "BoardView.h"

int main()
{
	Board board;
	BoardView view(&board);

	view.StartGame();
	
	return 0;
}