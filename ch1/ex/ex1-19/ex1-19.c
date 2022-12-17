/*
outline:
1. read the input *line*;
2. reverse the line;
3. print the reversed line.
*/
#include <stdio.h>
#define MAXLINE 1000

int getlineNew(char line[]);
void reverse(char to[], char from[]);

int main(void)
{
	int i;
	char line[MAXLINE];
	char rline[MAXLINE];

	while ((i = getlineNew(line)) > 1) {
		reverse(rline, line);
		printf("%s\n", rline);
	}
	return 0;
}

int getlineNew(char line[])
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		line[i] = c;
		++i;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	if (c == EOF) {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return i;
}

void reverse(char to[], char from[])
{
	int i, j;
	for (i = 0; from[i] != '\n'; ++i)
		;
	for (j = 0; j <= i; ++j) {
		to[j] = from[i - j - 1];
	}
	to[j] = '\n';
	++j;
	to[j] = '\0';
}