#include <stdio.h>

/*
You can try the script on ex1-8.txt
*/

int main(void)
{
    int blanks; // for counting the blanks
    int tabs; // for counting the tabs
    int nl; // for counting the lines

    blanks = 0;
    tabs = 0;
    nl = 0;

    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            blanks++;
            printf("b\n");
        }
        else if (c == '\t')
        {
            tabs++;
            printf("tab\n");
        }
        else if (c == '\n')
        {
            nl++;
        }
        else
            ;
    }

    // the last line
    if (nl != 0)
    {
        nl++;
    }

    printf("blanks: %i\n", blanks);
    printf("tabs: %i\n", tabs);
    printf("lines: %i\n", nl);

    return 0;
}
