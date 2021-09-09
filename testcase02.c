#include <stdio.h>
#include <stdlib.h>
#include "IrmaMoves.h"


int main(void)
{
	// Create a map board.
	char **board = createMapBoard();

	// Okay. Admittedly, this is super weird because it's not freeing the entire
	// board, which leaves us with a nasty memory leak. The whole point of this
	// test case is simply to ensure that you are dynamically allocating the 2D
	// board. If you're not, this will crash spectacularly. Of course, I decline
	// to free up all the dynamically allocated memory associated with the board
	// in this test case, because then I would be showing you exactly how to
	// write the destroyChessBoard() function.
	free(board[1]);

	printf("Hooray!\n");

	return 0;
}
