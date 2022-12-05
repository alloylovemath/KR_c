#include <stdio.h>

#define IN 1 // inside a word
#define OUT 0

int main(void)
{
	int c, nc, nw, nl, state;

	state = OUT;

	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	if (nc != 0)
		++nl;
	printf("characters: %d, words: %d, lines: %d\n", nc, nw, nl);
}