// This program is better to interact with a file
#include <stdio.h>

int main(void)
{
	long nc;
	
	/* Use while
	nc = 0;
	while (getchar() != EOF)
		++ nc;
	*/

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%ld\n", nc);
}