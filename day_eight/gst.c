#include <stdio.h>

int main()
{
    float a[6];
    int i;
    printf("enetr the prise of 6 items");
    for (i = 0; i < 6; i++)
    {
        scanf("%f", &a[i]);
    }
    for (i = 0; i < 6; i++)
    {
        // printf("%f",a[i]);
        printf("\n%f\n", a[i] + (0.18 * a[i]));
    }
}