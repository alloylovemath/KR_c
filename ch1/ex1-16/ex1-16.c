/*
The difficulty of this problem is that we can't modify the get_line function
following the requirement of the book.
The solution provided by ohkimur and DenSel86 modified the get_line function, so
it may not be "right".(source: https://github.com/ohkimur/the-c-programming-language-2nd-edition-solutions/blob/main/chapter_1/exercise_1_16/longest_line.c)
Here I might have find a funny way to solve it.
*/
#include <stdio.h>

#define MAXLINE 1000

// Nowadays, looks like C has already have a function named 'getline', so we
// change it to get_line
int get_line(char line[], int maxline);
void copy(char from[], char to[]);

int main(void)
{
	int len;
	char line[MAXLINE];

	int maxlen;
	char maxline[MAXLINE];

	maxlen = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
	{
		if (maxlen < len)
		{
			maxlen = len;
			copy(line, maxline);
		}

		/*
		Basically, I move the modified part from ohkimur and DenSel86's solution to
		here. to check if there are characters left behind.
		*/
		int tail = 0;
		int c = getchar();
		while (c != EOF && c != '\n')
		{
			tail++;
			c = getchar();
		}

		maxlen = maxlen + tail;
	}

	if (maxlen > 0)
	{
		printf("max length: %i\n", maxlen);
		printf("%s\n", maxline);
	}

	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

void copy(char from[], char to[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}
