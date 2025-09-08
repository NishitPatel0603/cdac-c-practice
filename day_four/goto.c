#include <stdio.h>
int main()
{
    if (1 == 0)
    {
        printf("hi!!!");
    }
    else
    {
        goto ti;
    }

ti:
    printf("nice");
}