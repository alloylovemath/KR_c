#include <stdio.h>

/* print Celsius-Fahrenheit table
for celsius = -30, -20, -10, ... , 100; floating-point version */

int main(void)
{
    float celsius, fahr;
    float lower, upper, step;

    lower = -30; /* lower limit of temperatuire scale */
    upper = 100; /* upper limit */
    step = 10; /* step size */

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;

        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
