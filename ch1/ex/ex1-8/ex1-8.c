#include <stdio.h>

int main(void)
{
    int blanks; // for counting the blanks
    int tabs; // for counting the tabs
    int nl; // for counting the lines
	int flag;

	flag = 0;

    blanks = 0;
    tabs = 0;
    nl = 0;

    int c;

    while ((c = getchar()) != EOF)
    {
		flag = 1;
        if (c == ' ')
        {
            ++blanks;
        }
        else if (c == '\t')
        {
            ++tabs;
        }
        else if (c == '\n')
        {
            ++nl;
        }
        else
            ;
    }

    // the last line
    if (flag != 0)
    {
        ++nl;
    }

    printf("blanks: %i\n", blanks);
    printf("tabs: %i\n", tabs);
    printf("lines: %i\n", nl);

    return 0;
}