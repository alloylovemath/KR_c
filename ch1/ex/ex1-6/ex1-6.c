#include <stdio.h>

int main(void)
{
    int value_of_assignment;

	/*
	A problem here is that when you type a character with you keyboard and press
	enter, you will get two same output.
	This is because the program treats enter as a character too!
	We can solve this by adding a test inside while, but maybe it's better
	to negnect it for beginners.
	When dealing with files, this won't bother.
	*/
	while ((value_of_assignment = (getchar() != EOF))) {
		printf("The value of the expression:");
		printf("'c = getchar() != EOF' is %d\n", value_of_assignment);
	}

	printf("\n");
	printf("The value of the expression:");
	printf("'(c = getchar()) != EOF' is %d\n", value_of_assignment);
}