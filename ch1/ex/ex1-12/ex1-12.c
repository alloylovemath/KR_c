/*
We define words the same way in the book: any sequence of characters that does
not contain a blank, tab or newline
*/
#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0

int main(void)
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			// at the end of a word print a newline character i.e. '\n'
			if (state == IN)
				putchar('\n');
			state = OUT;
		}
		// get into a word
		else if (state == OUT) {
			state = IN;
			putchar(c);
		}
		// still inside a word
		else
			putchar(c);
	}

	putchar('\n');
}