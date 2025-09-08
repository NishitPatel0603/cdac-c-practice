#include <stdio.h>

int main()
{
    int a = 12;
    int b =13;
    int *ptr1 = &b;
    int *ptr = &a;
    int temp;
    temp = *ptr;
    *ptr = *ptr1;
    *ptr1 = temp;

    printf("%d\t%d\n", *ptr, *ptr1);
}