#include <stdio.h>

int main()
{
    int a[] = {12, 45, 78, 2, 64}, n, i, temp;
    n = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    printf("reversed array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}