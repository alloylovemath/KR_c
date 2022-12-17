#include <stdio.h>
#define MAXLINE 1000

/*
In KR's book, the function name is getline, but it seems that there has been a
getline function in standard I/0 library, so I change it to getlineN (N for new)
Same process with copy, I change it to copyN
*/
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
		printf("The longest line is:\n");
		printf("%s", longest);
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
	int c, i;
	for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copyN(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
