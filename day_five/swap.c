#include <stdio.h>

int swap(int a, int c)
{
    int b = 0;
    b = c;
    c = a;
    a = b;
    printf("%d %d", a, c);
}

int main()
{
    swap(5, 2);
}