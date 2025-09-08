#include <stdio.h>

int main()
{
    int a[] = {12, 34, 565, 766, 43, 676, 434, 4567, 43, 89, 12, 456, 789, 457, 823, 59, 2, 8, 45, 3, 468, 45, 24, 68, 453};
    int large = 0;
    for (int i = 0; i < 25; i++)
    {
        if (a[i] >= large)
        {
            large = a[i];
        }
    }
    printf("%d", large);
}