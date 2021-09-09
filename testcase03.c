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

	// With this test case, I'm checking whether your parseNotationString()
	// function correctly parses through a string of algebraic notation.
	// This test case is also designed to help show you exactly which fields
	// should be set, and how they should be set, when parsing these strings.

	parseNotationString("e2 150 100 c3", &irmaMove);

	// Check that irma Move has been properly initialized.
	if (irmaMove.from_loc.col != 'e' || irmaMove.from_loc.row != 2)
		failwhale();
	if (irmaMove.to_loc.col != 'c' || irmaMove.to_loc.row != 3)
		failwhale();
	if (irmaMove.irma.ws != 150 || irmaMove.irma.wg != 100)
		failwhale();

	printf("Hooray!\n");

	return 0;
}
