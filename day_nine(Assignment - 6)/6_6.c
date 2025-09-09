#include <stdio.h>

int main()
{
    int x[8] = {10,20,30,40,50,60,70,80};
    printf("value of x %p\n", x);
    printf("value of x %p\n", x+2);
    printf("value of x %d\n", *x);
    printf("value of x %d\n", *(x+2));
    printf("value of x %p\n", (*x +2));

}