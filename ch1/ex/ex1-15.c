#include <stdio.h>

float fa_to_ce(int fahr);
float ce_to_fa(int celsius);

int main(void)
{
    // fahr temperatures and celsius temperatures
    int Fa_temps[15];
    int Ce_temps[15];

    for (int i = 0; i <= 15; i++)
    {
        Fa_temps[i] = 0 + 20 * i;
        Ce_temps[i] = -25 + 5 * i;
    }

    printf("Fahr to Celsius\n");
    for (int i = 0; i <= 15; i++)
    {
        printf("%3.0i, %6.2f\n", Fa_temps[i], fa_to_ce(Fa_temps[i]));
    }

    printf("Celsius to Fahr\n");
    for (int i = 0; i <= 15; i++)
    {
        printf("%3.0i, %6.2f\n", Ce_temps[i], ce_to_fa(Ce_temps[i]));
    }

    return 0;
}

float fa_to_ce(int fahr)
{
    float celsiu;

    celsiu = (5.0 / 9.0) * (fahr - 32);

    return celsiu;
}

float ce_to_fa(int celsiu)
{
    float fahr;

    fahr = ((9.0 / 5.0) * celsiu) + 32;

    return fahr;
}