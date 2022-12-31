/*
Well, this program has a premise-**there is no tab in the text**
because, actually, I don't quiet understand how tab work.... sry
*/
#include <stdio.h>

#define NS 80
#define IN 1 // for in words and sentences
#define OUT 0 // for out words and sentences

int stateW, stateS;
int j = 0;

int read_line(char line[], char words[]);

int main(void)
{
	int c;
	char line[NS + 1]; // '+1' for '\0'
	char words[NS]; // for remember words

	stateW = OUT;
	stateS = OUT;

	while (read_line(line, words) > 0)
	{
		printf("%s", line);
	}
	printf("%s", line);
	return 0;
}

int read_line(char line[], char words[])
{
	int c, i;
	extern int stateS, stateW, j;

	i = 0;

	for (int k = 0; k < j; ++k)
	{
		line[i] = words[k];
		++i;
	}

	while ((c = getchar()) != EOF && i < NS)
	{
		if (c == '\n')
		{
			line[i] = c;
			line[i+1] = '\0';
			i = 0;
			j = 0;
			stateS = OUT;
			stateW = OUT;
			return 1;
		}
		else if (c == ' ')
		{
			line[i] = c;
			stateS = IN;
			stateW = OUT;
			++i;
			j = 0;
		}
		else
		{
			line[i] = c;
			words[j] = c;
			stateS = IN;
			stateW = IN;
			++i;
			++j;
		}
	}

	if (c == EOF)
	{
		line[i] = '\n';
		line[i + 1] = '\0';
		return 0;
	}

	if (stateW == IN)
	{
		line[i - j] = '\n';
		line[i - j + 1] = '\0';
		return 1;
	}
	else
	{
		line[i] = '\n';
		line[i + 1] = '\0';
		return 1;
	}
}