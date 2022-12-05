#include <stdio.h>

int main(void)
{
    int fahr;

    /* for statement: 
    first statement is initialization;
    second is test;
    the third is the increment step
    
    these three statements can be any expressions*/
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}