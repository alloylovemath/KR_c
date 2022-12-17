#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

int getlineTailFree(char line[], char tline[], int lim);
void copyN(char to[], char from[]);

int main(void)
{
	int i;
	char line[MAXLINE];
	char tline[MAXLINE];
	char pline[MAXLINE];
	while ((i = getlineTailFree(line, tline, MAXLINE)) > 0) {
		if (i > 1) {
			copyN(pline, line);
			printf("%s", pline);
			printf("\n");
		}
	}
	return 0;
}

int getlineTailFree(char line[], char tline[], int lim)
{
	int c, i, j, k;
	int state = OUT;

	k = j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 2) {
			if (state == OUT && c != ' ' && c != '\t') {
				line[j] = c;
				++j;
			}
			else if (c == ' ' || c == '\t') {
				tline[k] = c;
				++k;
				state = IN;
			}
			else if (state == IN && c != ' ' && c != '\t') {
				for (int s = 0; s < k; ++s) {
					line[j] = tline[s];
					++j;
				}
				line[j] = c;
				state = OUT;
				k = 0;
			}
		}
	}
	if (c == '\n') {
			line[j] = '$';
			++j;
			++i;
		}
	line[j] = '\0';
	return i;
}

void copyN(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}