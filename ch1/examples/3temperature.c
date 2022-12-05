/*
This script is from section 1.4.

Besides the 'int main(void)' part,
we shall pay attention to the 'printf' part inside the for loop.
We use '%i' instead of '%d'(also work).
*/

#include <stdio.h>

/*
Those are symbolic constant.
They work like variables but they are not variables.
So they do not appear in declarations.
Notice that there are no ';' at the ends of '#define' line.
symbolic constant are conventionally written in upper case.
*/
#define LOWER 0 /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20 /* step size */

/* print Fahrenheit-Celsius table */
int main(void)
{
int fahr;

for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3i %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

}