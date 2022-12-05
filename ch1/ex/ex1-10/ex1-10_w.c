/*
This program is for creating `ex1-10.txt`, since it's hard (or impossible) to
input `\b` with keyboard.
*/
#include <stdio.h>

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