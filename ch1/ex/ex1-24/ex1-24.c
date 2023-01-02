/*
get some inspiration from the C Answer Book
we will assume that there are only 3 types of rudimentary syntax errors like
unbalanced parentheses, brackets and braces, and we will ignore every thing
inside a string (i.e. inside quotes) or comments
*/
#include <stdio.h>

void search_error(int c);
void in_comment(void);
void in_quote(int c);

int parentheses, brackets, braces;

int main(void)
{
	int c;
	extern int parentheses, brackets, braces;

	parentheses = brackets = braces = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '/')
		{
			if ((c = getchar()) == '*')
			{
				in_comment();
			}
			else
			{
				search_error(c);
			}
		}
		else if (c == '\'' || c == '"')
		{
			in_quote(c);
		}
		else
		{
			search_error(c);
		}

		if (braces < 0)
		{
			printf("Unbalance braces\n");
			braces = 0;
		}
		else if (brackets < 0)
		{
			printf("Unbalance brack\n");
			brackets = 0;
		}
		else if (parentheses < 0)
		{
			printf("Unbalance parentheses\n");
			parentheses = 0;
		}
	}

	if (braces > 0)
	{
		printf("Unbalance braces\n");
	}
	else if (brackets > 0)
	{
		printf("Unbalance brack\n");
	}
	else if (parentheses > 0)
	{
		printf("Unbalance parentheses\n");
	}
}

void search_error(int c)
{
	extern int braces, brackets, parentheses;

	if (c == '{')
	{
		++braces;
	}
	else if (c == '}')
	{
		--braces;
	}
	else if (c == '[')
	{
		++brackets;
	}
	else if (c == ']')
	{
		--brackets;
	}
	else if (c == '(')
	{
		++parentheses;
	}
	else if (c == ')')
	{
		--parentheses;
	}
}

void in_comment(void)
{
	int d, e;

	d = getchar();
	e = getchar();

	while (d != '*' || e != '/')
	{
		d = e;
		e = getchar();
	}
}

void in_quote(int c)
{
	int d;

	while ((d = getchar()) != c)
	{
		if (d == '\\')
		{
			getchar();
		}
	}
}