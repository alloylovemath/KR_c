#include <stdio.h>

#define IN 1 // inside a sequence of space
#define OUT 0 // outside a sequence of space

int main(void)
{
	int c;

	int flag;
	flag = OUT;

	while ((c = getchar()) != EOF)
	{
		// if we counter a space and we are not inside a sequence of space
		// we shall print the space and set flag to 'IN'
		if (c == ' ' && flag == OUT)
		{
			putchar(c);
			flag = IN;
		}
		// if we counter a space and we are inside a sequence of space
		// we shall do nothing
		else if (c == ' ' && flag == IN)
		{
			;
		}
		else
		{
			putchar(c);
			flag = OUT;
		}
	}

	// better output style
	printf("\n");
	return 0;
}
