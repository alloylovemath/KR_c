/*
Nowadays, there are two kinds comments in C
But I will assume that there is only one comment specification method
*/
#include <stdio.h>

#define IN 1 /* inside a comment */
#define OUT 0
#define MAXLINE 1000

int state = OUT;

int getlineN(char line[], int maxline);
int removeComment(char pline[], char line[], int length);

int main(void)
{
	int len;
	char line[MAXLINE], pline[MAXLINE];

	while ((len = getlineN(line, MAXLINE)) > 0)
	{
		if (removeComment(pline, line, len) == 1)
		{
			printf("%s", pline);
		}

	}
	return 0;
}

int getlineN(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	return i;
}

int removeComment(char pline[], char line[], int length)
{
	extern int state;
	int incomment;

	if (line[length - 1] == '\n')
	{
		incomment = length - 1;

		if (state == IN)
		{
			for (int k = 0; k < length - 2; ++k)
			{
				if (line[k] == '*' && line[k + 1] == '/')
				{
					state = OUT;
				}
			}
			return 0;
		}
		else
		{
			int flag = 0;

			for (int k = 0; k < length - 2; ++k)
			{
				if (line[k] == '/' && line[k + 1] == '*')
				{
					incomment = k - 1;
					state = IN;
				}
			}

			if (line[length - 3] == '*' && line[length - 2] == '/')
			{
				flag = 1;
				state = OUT;
			}

			if (incomment == 0)
			{
				return 0;
			}

			for (int j = 0; j <= incomment; ++j)
			{
				pline[j] = line[j];
			}

			if (flag == 1)
			{
				pline[incomment + 1] = '\n';
				pline[incomment + 2] = '\0';
			}
			else
			{
				pline[incomment + 1] = '\0';
			}
			return 1;
		}
	}
	else
	{
		incomment = length - 1;

		if (state == IN)
		{
			for (int k = 0; k < length - 1; ++k)
			{
				if (line[k] == '*' && line[k + 1] == '/')
				{
					state = OUT;
				}
			}
			return 0;
		}
		else
		{
			int flag = 0;

			for (int k = 0; k < length - 1; ++k)
			{
				if (line[k] == '/' && line[k + 1] == '*')
				{
					incomment = k - 1;
					state = IN;
				}
			}

			if (line[length - 2] == '*' && line[length - 1] == '/')
			{
				flag = 1;
				state = OUT;
			}

			if (incomment == 0)
			{
				return 0;
			}

			for (int j = 0; j <= incomment; ++j)
			{
				pline[j] = line[j];
			}

			if (flag == 1)
			{
				pline[incomment + 1] = '\n';
				pline[incomment + 2] = '\0';
			}
			else
			{
				pline[incomment + 1] = '\0';
			}
			return 1;
		}
	}
}