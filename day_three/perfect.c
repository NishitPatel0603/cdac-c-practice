#include <stdio.h>
#include <math.h>
int main()
{
    int a, i, sum = 0;
    printf("enter the number ");
    scanf("%d", &a);
    for (i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == a)
    {
        printf("it is a per num: %d", a);
    }
    else
    {
        printf("it is not a per num :%d", a);
    }
}