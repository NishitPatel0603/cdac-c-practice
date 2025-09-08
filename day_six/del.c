#include <stdio.h>

int main()
{
    int a[] = {12, 45, 78, 2, 64, 848, 12, 8, 2, 1, 81, 28, 56, 14, 86, 84, 74, 76, 21, 55, 14};
    int del, i;
    for (i = 0; i <= 20; i++)
    {
        printf("inex %d value %d\n", i, a[i]);
    }
    printf("enter the valu you want to remove:");
    scanf("%d", &del);
    for (i = 0; i <= a[del]; i++)
    {
        if (del == i)
        {
            a[i] = 0;
        }
    }
    for (i = a[del - 1]; i <= 20; i++)
    {
        a[i] = a[i + 1];
    }
    for (i = 0; i <= 20; i++)
    {
        printf("inex %d value %d\n", i, a[i]);
    }
}