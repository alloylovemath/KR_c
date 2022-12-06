#include <stdio.h>

int main(void)
{
	int c, nwhite, nother;
	int ndigits[10];

	nwhite = nother = 0;
	for (int i = 0; i < 10; ++i)
		ndigits[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			++ndigits[c - '0'];
		}
		else if (c == ' ' || c == '\t' || c == '\n') {
			++nwhite;
		}
		else {
			++nother;
		}
	}

	printf("digits: \n");
	for (int i = 0; i < 10; ++i)
		printf("%d: %d\n", i, ndigits[i]);
	printf("whites: %d\n", nwhite);
	printf("other chars: %d\n", nother);

	return 0;
}