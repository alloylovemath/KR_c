#include <stdio.h>

/*
use this scipt to write a txt file containing backspace
*/

int main(void)
{
	FILE *file = fopen("ex1-10.txt", "w");
	if (!file)
	{
		return 1;
	}
	char *s = "sdsdsdsds\bAA\t\\sssssssss\n";

	fprintf(file, "%s", s);
	fclose(file);

	return 0;
}
