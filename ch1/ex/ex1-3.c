#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */

    fahr = lower;
  // title here
	printf("fahr celsius\n");
    while (fahr <= upper) {
        /* '5 / 9' will lead to integer division truncate: any fractional part
        is discarded. */
        celsius = (5.0/9.0) * (fahr-32.0);

        /* '%6.1f' means that print the float number
        6 characters wide with 1 character after the decimal point */
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
