#include <stdio.h>

/*
make sure you have run ex1-10_w.c already
*/

int main(void)
{
	int c;

	while((c = getchar()) != EOF)
	{
		if (c == '\b')
		{
			putchar('\\');
			putchar('b');
		}
		else if (c == '\t')
		{
			putchar('\\');
			putchar('t');
		}
		else if (c == '\\')
		{
			putchar('\\');
			putchar('\\');
		}
		else
		{
			putchar(c);
		}
	}

	return 0;
}
