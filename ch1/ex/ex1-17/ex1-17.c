#include <stdio.h>
#define MAXLINE 1000
#define FLAG 80

int getlineN(char line[], int lim);
void copyN(char to[], char from[]);

int main(void)
{
	int i;
	char line[MAXLINE];
	char pline[MAXLINE];
	while ((i = getlineN(line, MAXLINE)) > 0) {
		if (i > 80) {
			copyN(pline, line);
			printf("%s\n", pline);
		}
	}

	return 0;
}

int getlineN(char line[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 2) {
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}
	if (i > j)
		++i;
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