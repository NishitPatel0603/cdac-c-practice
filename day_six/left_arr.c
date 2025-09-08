#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int stor;
    stor = a[0];
    for (int i = 0; i <= 9; i++)
    {
        a[i] = a[i + 1];
    }
    a[9] = stor;
    for (int i = 0; i <= 9; i++)
    {
        printf("%d\t", a[i]);
    }
}