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

	Move irmaMove;

	// Create a map struct for this test case.
	char **finalBoardState = predictIrmaChange("g7 150 100 f6", &irmaMove);
	if (irmaMove.irma.ws != 141 || irmaMove.irma.wg != 93)
		failwhale();
	printf("Hooray!\n");

	// Destroy the map board returned by predictIrmaChange().
	finalBoardState = destroyMapBoard(finalBoardState);


	return 0;
}
