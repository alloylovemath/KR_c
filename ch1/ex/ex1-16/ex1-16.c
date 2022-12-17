/*
This script is derived from The C Answer Book (2nd ed.)
I don't write it because I don't get the exact meaning of ex1-16 in the start...

There is only two revision compared to 11longestLine.c:
1. we print the length of the longest line;
2. we rewrite the getlineN function.
*/
#include <stdio.h>
#define MAXLINE 1000

int getlineN(char line[], int maxline);
void copyN(char to[], char from[]);

int main(void)
{
	int len, max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getlineN(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copyN(longest, line);
		}
	}

	if (max > 0) {
		printf("The length of the longest line is: %d\n", max);
		printf("The longest line is (may not complete): \n");
		printf("%s\n", longest);
	}
	return 0;
}

/*
getlineN does two things:
1. read the line into array line;
2. return its length.
*/
int getlineN(char line[], int maxline)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < maxline - 2) {
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}
	line[j] = '\0';
	return i;
}

void copyN(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}