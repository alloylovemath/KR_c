/*
Let's draw a horizontal version.
we can have a vertical one, but, problem is that the histogram might be too
wide, so that it looks bad.
*/
#include <stdio.h>

int main(void)
{
	/*
	let's only deal with English letters (uppercase and lowercase), digits, and
	let other characters as others.
	If not, the program might be two complicated.
	*/
	int c, nothers, flag;
	float uletters[26]; // uppercase
	float lletters[26]; // lowercase
	float digits[10];
	/*
	we use freq to represent the frequency. and we shall multiply the real
	frequency by 100, and round the number, i.e. 0.637 will be 64.
	*/
	int freq;

	flag = 0;
	nothers= 0;
	for (int i = 0; i < 26; ++i) {
		uletters[i] = 0;
		lletters[i] = 0;
	}
	for (int i = 0; i < 10; ++i)
		digits[i] = 0;
	
	while ((c = getchar()) != EOF) {
		flag = 1;
		if (c >= '0' && c <= '9')
			++digits[c - '0'];
		else if (c >= 'a' && c <= 'z')
			++lletters[c - 'a'];
		else if (c >= 'A' && c <= 'Z')
			++uletters[c - 'A'];
		else
			++nothers;
	}

	
	// calculate the sum
	int aggregate = 0;
	// letters and digits
	for (int i = 0; i < 26; ++i)
		aggregate = aggregate + uletters[i] + lletters[i];
	for (int i = 0; i < 10; ++i)
		aggregate = aggregate + digits[i];
	
	// others
	aggregate = aggregate + nothers;

	// let's draw the histogram
	for (int i = 0; i < 26; ++i) {
		if (lletters[i] > 0) {
			printf("%c: ", 'a' + i);
			// calculate the freq. Notice how we round the number
			freq = (int) ((100 * (lletters[i] / aggregate)) + 0.5);
			// for better looking, we add a # nomatter how small a positive freq
			// is.
			putchar('#');
			for (int j = 0; j < freq; ++j)
				putchar('#');
			putchar('\n');
		}
		if (uletters[i] > 0) {
			printf("%c: ", 'A' + i);
			// calculate the freq. Notice how we round the number
			freq = (int) ((100 * (uletters[i] / aggregate)) + 0.5);
			putchar('#');
			for (int j = 0; j < freq; ++j)
				putchar('#');
			putchar('\n');
		}
	}

	for (int i = 0; i < 10; ++i) {
		if (digits[i] > 0) {
			printf("%c: ", '0' + i);
			freq = (int) ((100 * (digits[i] / aggregate)) + 0.5);
			putchar('#');
			for (int j = 0; j < freq; ++j)
				putchar('#');
			putchar('\n');
		}
	}

	if (nothers > 0) {
		printf("*: ");
		freq = (int) ((100 * (nothers / aggregate)) + 0.5);
		putchar('#');
		for (int j = 0; j < freq; ++j)
			putchar('#');
		putchar('\n');
	}

	return 0;
}