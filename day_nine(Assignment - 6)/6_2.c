#include <stdio.h>

int main()
{
    int a = 12;
    int *p = &a;
    printf("%d \t %p", *p, &p);

}