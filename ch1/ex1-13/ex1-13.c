/*
This program is inspired by the code writen by ohkimur and DenSel86 (both of
them are github usernames).
You can look up for their solution on:
https://github.com/ohkimur/the-c-programming-language-2nd-edition-solutions/blob/main/chapter_1/exercise_1_13/histogram.c
*/

#include <stdio.h>

#define IN 1
#define OUT 0

#define MAX_WORD_LENGTH 100

int main(void)
{
	/*
	Initialize an array to record the lengths of words from input.
	We assume that the max length will not be greater than 100 (pretty realistic
	right?), which is the MAX_WORD_LENGTH. And there will be an extra position
	showing the exact max length of the input, so that the length of the array
	will be 101.
	*/
	int histogram[MAX_WORD_LENGTH];
	int max_length_input = 0;

	// initialize the array
	for (int i = 0; i <= 100; i++)
	{
		histogram[i] = 0;
	}

	int state = OUT;

	int c;
	int word_length = 0;

	while ((c = getchar()) != EOF)
	{
		/*
		let's assume that the input only cover characters, blank, tabs and new
		lines.
		*/
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (word_length > 0)// we have gone through a word
			{
				state = OUT;
				histogram[word_length - 1]++;
				
				// check if the length is the longer than the longest
				if (word_length > max_length_input)
				{
					max_length_input = word_length;
				}
				word_length = 0;
			}
			else
			{
				/*
				Here, the other scenario is that there are non-char at the
				beginning. So we do nothing
				*/
				;
			}
		}
		else
		{
			state = IN;
			word_length++;
		}
	}

	/*
	There is a problem in ohkimur and DenSel86' solution, that is if there is a
	word at the end of the input (no blank behind), it will omit it.
	Here is the revise-check if we are still 'IN' a word after the while loop.
	*/
	if (state == IN)
	{
		histogram[word_length - 1]++;

		if (word_length > max_length_input)
			{
				max_length_input = word_length;
			}
	}

	// at the max_length_input position, we make a notation
	histogram[max_length_input] = '$';

	// Now, draw the horizontal histogram
	printf("the horizontal histogram of lengths of words\n");

	int index = 1;
	int len;
	while ((len = histogram[index - 1]) != '$')
	{
		if (len > 0)
		{
			printf("%2i: ", index);
			for (int i = 0; i < len; i++)
			{
				printf("#");
			}
			printf("\n");
		}
		index++;
	}

	printf("-----------------------------------------------------------\n\n");

	/*
	Now, let's draw the vertical histogram.
	As the book said, it is harder to draw the vertical one. But I will try to
	give a solution.
	*/
	printf("The vetical histogram of lengths of words\n");

	// first, let's get the height of the histogram
	// ie. find out the biggest number in the array
	int height = 0;

	for (int i = 0; i < max_length_input; i++)
	{
		if (histogram[i] > height)
		{
			height = histogram[i];
		}
	}


	// Now draw the histogram one layer at a time form top to bottom.
	for (int i = height; i >= 1; i--)
	{
		for (int j = 0; j < max_length_input; j++)
		{
			if (histogram[j] > 0)
			{
				if (histogram[j] >= i)
				{
					printf(" # ");
				}
				else
				{
					printf("   ");
				}
			}
		}
		printf("\n");
	}

	// draw the base
	for (int i = 0; i < max_length_input; i++)
	{
		if (histogram[i] > 0)
		{
			printf(" %i ", i+1);
		}
	}
	printf("\n");
	return 0;
}
