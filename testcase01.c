#include <stdio.h>
#include <stdlib.h>
#include "IrmaMoves.h"


void failwhale(void)
{
	printf("fail whale :(\n");
	exit(0);
}

int main(void)
{
	// Create a map board.
	char **board = createMapBoard();

	// Check that some of lands and ocean squares are in the correct positions.
	if (board[0][1] != 'F')
		failwhale();
	if (board[4][2] != 'K')
		failwhale();
	if (board[5][3] != 'B')
		failwhale();
	if (board[2][0] != ' ')
		failwhale();

	printMapBoard(board);

	printf("Hooray!\n");

	return 0;
}
