#include <stdio.h>

int main(void)
{
	int c, nl, flag;
	
	flag = 0;
	nl = 0;
	while ((c = getchar()) != EOF) {
		flag = 1;
		if (c == '\n')
			++nl;
	}
	
	if (flag == 0)
		printf("0\n");
	else
		printf("%d\n", nl + 1);
}